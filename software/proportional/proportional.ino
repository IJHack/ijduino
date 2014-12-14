#include "LedControl.h" //  need the library
#include <OneWire.h>
#include "PropFont.h"
// Data wire is plugged into port 10 on the Arduino
#define ONE_WIRE_BUS 10

static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;
static const int DISPLAYS = 1;

static const int DELAY = 50;

//LedControl lc=LedControl(12,11,10,6); // 6 matrices, 6 MAX7219s.
LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, DISPLAYS);

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire ds(ONE_WIRE_BUS);

int count = 0;
char msg[80] = "           IJhack temp test :-)";

int msgsize =  strlen(msg);
int curcharix = 0;
int curcharbit = 0;
int curcharixsave = 0;
int curcharbitsave = 0;
int curcharixsave2 = 0;
int curcharbitsave2 = 0;
char curchar;

void setup()

{
	for (int i = 0; i < DISPLAYS; i++) {
		lc.shutdown(i,false);// turn off power saving, enables display
		lc.setIntensity(i,15);// sets brightness (0~15 possible values)
		lc.clearDisplay(i);// clear screen
	}
	checkTemp();
}

void checkTemp()
{
	byte i;
	byte present = 0;
	byte type_s;
	byte data[12];
	byte addr[8];

	if ( !ds.search(addr)) {
		if (count == 0) {
			strncpy(msg, "          No thermometer found.", 80);
			msgsize =  strlen(msg);
			return;
		}
		ds.reset_search();
		delay(250);
		count = 0;
		return;
	}

	ds.reset();
	ds.select(addr);
	ds.write(0x44, 1);        // start conversion, with parasite power on at the end

	delay(1000);     // maybe 750ms is enough, maybe not
	// we might do a ds.depower() here, but the reset will take care of it.

	present = ds.reset();
	ds.select(addr);    
	ds.write(0xBE);         // Read Scratchpad

	for ( i = 0; i < 9; i++) {           // we need 9 bytes
		data[i] = ds.read();
	}

	// Convert the data to actual temperature
	// because the result is a 16 bit signed integer, it should
	// be stored to an "int16_t" type, which is always 16 bits
	// even when compiled on a 32 bit processor.
	int16_t raw = (data[1] << 8) | data[0];
	if (type_s) {
		raw = raw << 3; // 9 bit resolution default
		if (data[7] == 0x10) {
			// "count remain" gives full 12 bit resolution
			raw = (raw & 0xFFF0) + 12 - data[6];
		}
	} 
	else {
		byte cfg = (data[4] & 0x60);
		// at lower res, the low bits are undefined, so let's zero them
		if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
		else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
		else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
		//// default is 12 bit resolution, 750 ms conversion time
	}

	float temp = (float)raw / 16.0;
	int itemp = int(temp);

	count ++;
	sprintf(msg, "       Zone %d: %d.%d'C", count, itemp, int((temp-itemp)*100));

	msgsize =  strlen(msg);
}



void loop()
{
	int i,j,k;
        for (;;)
	{
		curcharixsave2 = curcharix;
		curcharbitsave2 = curcharbit;

		for (i=DISPLAYS;i>=0;i--) // Loop through our 1 display
		{
			for (j=0;j<8;j++) // Set up rows on current  display
			{      
				byte outputbyte = 0;
                                curchar = msg[curcharix];
				curcharixsave = curcharix;
				curcharbitsave = curcharbit;
				for (k=7;k>=0;k--) // Copy over data for 8 columns to current row and send it to current display
				{
					// This byte is the bitmap of the current character for the current row
					byte currentcharbits = pgm_read_byte(&Font8x5[((curchar-32)*8)+j]);
					if (currentcharbits & (1<<curcharbit))
						outputbyte |= (1<<k);

					// advance the current character bit of current character
					curcharbit ++;

					if (curcharbit > pgm_read_byte(&lentbl_S[curchar-32])) // we are past the end of this character, so advance.
					{
						curcharbit = 0;
						curcharix += 1;          
						if (curcharix+1 > msgsize) curcharix=0;
						curchar = msg[curcharix];
					}
				}

				lc.setColumn(i, 7-j, outputbyte);

				if (j != 7) // if this is not the last row, roll back advancement, if it is, leave the counters advanced.
				{
					curcharix = curcharixsave;
					curcharbit = curcharbitsave;
				}

			}

		}

		curcharix = curcharixsave2;
		curcharbit = curcharbitsave2;

		curchar = msg[curcharix];

		// advance the current character bit of current character
		curcharbit ++;

		if (curcharbit > pgm_read_byte(&lentbl_S[curchar-32])) // we are past the end of this character, so advance.
		{
			curcharbit = 0;
			curcharix += 1;
			if (curcharix+1 > msgsize)  {
				checkTemp(); 
				curcharix=0;
			}
			curchar = msg[curcharix];

		}

		delay(DELAY);
	}
}

