/*                            IJduino 1.1
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

/* using VCC, GND, DIN 20, CS 21, CLK 5 for the MAX7219 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);


