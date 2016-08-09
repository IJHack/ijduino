/*
 * new sticker
 * 
 * Displays rotating text send to RX pin. The text
 * should be terminated with newline character.
 * Received text is echoed to TX pin.
 * See http://www.iwriteiam.nl/D1607.html#19b for
 * how to connect HC-06 bluetooth module with
 * two resistors of 1Kohm and 1.8kohm to IJduino,
 * such that bluetooth app can be used to update
 * text.
 */
#include "font.h"
#include "LedControl.h"


/* using VCC, GND, DIN 20, CS 21, CLK 5 for the MAX7219 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

byte matrix[8];
byte textbuffer[65] = "TkkrLab is cool \\o/ ";
byte *cur_char;

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
  for (uint8_t i = 0; i < 8; i++)
    matrix[i] = 0;
  cur_char = textbuffer;
}

void display_shift()
{
  for (uint8_t i = 0; i < 8; i++)
    lc.setRow(0, i, matrix[i]);
  for (uint8_t i = 0; i < 7; i++)
    matrix[i] = matrix[i+1];
  matrix[7] = 0;
  delay(50);
  Serial.begin(9600);
}

void letter (const byte c)
{
  display_shift();

  for (byte col = 0; col < 8; col++) {
    matrix[7] = pgm_read_byte (&cp437_font [c] [col]);
    display_shift();
  }
}

void loop () 
{
  byte len = 0;
  if (Serial.available())
    len = Serial.readBytesUntil(10, textbuffer, 64);
  
  if (len > 0)
  {
    textbuffer[len] = '\0';
    Serial.print("I received: ");
    Serial.println((char*)textbuffer);
    cur_char = textbuffer;
  }
  else
  {
    if (*(++cur_char) == '\0')
      cur_char = textbuffer;
  }
  //Serial.print("Display: ");
  //Serial.println(*cur_char, DEC);    
  letter(*cur_char);
}



