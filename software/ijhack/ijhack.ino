#include "LedControl.h"

LedControl lc=LedControl(20,5,21,1);

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

void render(byte* animation, int delaytime) {
  lc.setColumn(0,0,animation[7]);
  lc.setColumn(0,1,animation[6]);
  lc.setColumn(0,2,animation[5]);
  lc.setColumn(0,3,animation[4]);
  lc.setColumn(0,4,animation[3]);
  lc.setColumn(0,5,animation[2]);
  lc.setColumn(0,6,animation[1]);
  lc.setColumn(0,7,animation[0]);
  delay(delaytime);
} 

void invade(int times = 1) {
   byte invade[8]={
B00100100,
B00100100,
B01111110,
B11011011,
B11111111,
B11111111,
B10100101,
B00100100};

byte devade[8]={
B00100100,
B10100101,
B11111111,
B11011011,
B11111111,
B01111110,
B00100100,
B00100100};
 
  for (int i = 1; i < times; i++) {
    render(invade, 1000);
    render(devade, 1000);  
  }
}

void invadesquid(int times = 1) {
   byte invadesquid[8]={
B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B01011010,
B10000001,
B01000010};

   byte devadesquid[8]={
B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01011010,
B10100101};

  for (int i = 1; i < times; i++) {
    render(invadesquid, 1000);
    render(devadesquid, 1000);  
  }
}

void ijlogowink(int times = 1) {
  byte logowink0[8]={
B11000011,
B11000011,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};

   byte logowink1[8]={  
B00000011,
B00000011,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};

  for (int i = 1; i < times; i++) {  
    render(logowink0, 500);
    render(logowink1, 500);
  }
}

void ijhacklogo() {
  /* here is the data for the characters */
  byte ij[8]={
B11000011,
B11000011,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};

   byte h[8]={
B11000011,
B11000011,
B11000011,
B11111111,
B11111111,
B11000011,
B11000011,
B11000011 };

   byte a[8]={
B00011000,
B00111100,
B01100110,
B11000011,
B11111111,
B11111111,
B11000011,
B11000011 };

   byte c[8]={
B01111110,
B11111111,
B11000011,
B11000000,
B11000000,
B11000011,
B11111111,
B01111110 };
   
   byte k[8]={
B11000111,
B11011110,
B11111100,
B11110000,
B11110000,
B11111100,
B11011110,
B11000111
 };

  render(ij, 500);
  render(h, 500);
  render(a, 500);
  render(c, 500);
  render(k, 500);
}

void heart(int times = 1) {
  
  /* here is the data for the characters */
  byte heart2[8]={B00000000,
B01100110,
B10011001,
B10000001,
B10000001,
B01000010,
B00100100,
B00011000};

  /* here is the data for the characters */
  byte heart1[8]={
B00000000,
B01100110,
B11111111,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000};

  for (int i = 1; i < times; i++) {
    render(heart1, 500);
    render(heart2, 500); 
  }
}

void loop() {
  ijlogowink(4);
  delay (1000);
  ijhacklogo();
  invade(7);
  delay (1000);
  heart(4);
  lc.clearDisplay(0);
  delay (1000);
  
}
