#include "font.h"
#include "LedControl.h"


/* using VCC, GND, DIN 20, CS 21, CLK 5 for the MAX7219 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

void setup() {
  /*
	   The MAX72XX is in power-saving mode on startup,
   	   we have to do a wakeup call
   	 */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,15);
  /* and clear the display */
  lc.clearDisplay(0);
}

void letter (const byte c)
{
  for (byte col = 0; col < 8; col++) {
    // ijduino is 90 degrees turned compared to 'normal' operation
    lc.setRow(0, col, pgm_read_byte (&cp437_font [c] [col]));
  }
}  // end of letter


void showString (const char * s, const unsigned long time)
{
  char c;
  while (c = *s++)
  {
    letter (c); 
    delay (time);
  }
}  // end of showString

void loop () 
{
  showString ("IJhack is f*cking cool !%$#@& \\o/ ", 500);
}  //



