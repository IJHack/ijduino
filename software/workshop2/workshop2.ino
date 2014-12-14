/*                            IJduino 1.4
Requires:
 * 8X8 LED grid MAX7219
 * Mini Breadboard
 * Atmega328
 * Button
 * 2 Wires
 * 4.5 Volt
 (c) IJhack 2014 GNU GPL 
http://ijhack.org/
 */
#include "LedControl.h"

// animations
#include "menuitems.h"

/* using VCC, GND, DIN 20, CS 21, CLK 5 for the MAX7219 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

static const int INTENSITY = 5;
static const int DISPLAYS = 1;

/* choose the input pin for the pushbutton */
static const int buttonPin = 9;           



LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, DISPLAYS);

// byte screen[DISPLAYS][8];
byte screen[8];

const byte* menuscreen[5][8] = {ij, h, a, c, k};

// basic startup
int lastButtonState = LOW;   /* the previous reading from the input pin */
unsigned long lastDebounceTime = 0;   /* the last time the output pin was toggled */
unsigned long debounceDelay = 50;     /* the debounce time; increase if the output flickers */
int animation = 0;
int animations = 0;
int buttonState = LOW;
int shift = 0;

void setup() {
	/*
	   The MAX72XX is in power-saving mode on startup,
	   we have to do a wakeup call
	 */
	lc.shutdown(0,false);
	/* Set the brightness value */
	lc.setIntensity(0,INTENSITY);
	/* and clear the display */
	lc.clearDisplay(0);
	/* setup pins */
	pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
	bool skip;

        
        load(ij);

        render(screen, 0);
                
        readinput(1000);        
                
        load(a);
        
        render(screen, 0);
        
        readinput(1000);
                
}

void moveleft() {
  shift++;
  if (shift > 7) {
   shift = 0;
  } 
}

void load(const byte* frame) {

        for (int r = 0; r < 8; r++) {
          screen[r] = pgm_read_byte(&frame[r]);
        }
        
}
