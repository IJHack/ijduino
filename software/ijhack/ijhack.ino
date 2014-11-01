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
    render(invade, 500);
    render(devade, 500);  
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
    render(invadesquid, 500);
    render(devadesquid, 500);  
  }
}


void ghost(int times = 1) {

 byte ghost1[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};

 byte ghost2[8]={
B00000000,
B00000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000};

 byte ghost3[8]={
B00000000,
B10000000,
B11000000,
B01000000,
B11000000,
B11000000,
B11000000,
B01000000};


 byte ghost4[8]={
B10000000,
B11000000,
B01100000,
B00100000,
B11100000,
B01100000,
B11100000,
B00100000};


 byte ghost5[8]={
B11000000,
B11100000,
B10110000,
B10010000,
B11110000,
B00110000,
B11110000,
B01010000};



 byte ghost6[8]={
B11100000,
B11110000,
B01011000,
B01001000,
B11111000,
B00011000,
B11111000,
B10101000};


 byte ghost7[8]={
B01110000,
B11111000,
B10101100,
B00100100,
B11111100,
B10001100,
B11111100,
B01010100};




  byte ghost8[8]={
B00111000,
B01111100,
B11010110,
B10010010,
B11111110,
B11000110,
B11111110,
B10101010};

byte ghost9[8]={
B00011100,
B00111110,
B01101011,
B01001001,
B01111111,
B01100011,
B01111111,
B01010101};

byte ghost10[8]={
B00001110,
B00011111,
B00110101,
B00100100,
B00111111,
B00110001,
B00111111,
B00101010};

byte ghost11[8]={
B00000111,
B00001111,
B00011010,
B00010010,
B00011111,
B00011000,
B00011111,
B00010101};

byte ghost12[8]={
B00000011,
B00000111,
B00001101,
B00001001,
B00001111,
B00001100,
B00001111,
B00001010};

byte ghost13[8]={
B00000001,
B00000011,
B00000110,
B00000100,
B00000111,
B00000110,
B00000111,
B00000101};

byte ghost14[8]={
B00000000,
B00000001,
B00000011,
B00000010,
B00000011,
B00000011,
B00000011,
B00000010};
 
byte ghost15[8]={
B00000000,
B00000000,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001};


byte ghost16[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};


  for (int i = 1; i < times; i++) {
    render(ghost1, 200);
    render(ghost2, 200);  
    render(ghost3, 200);
    render(ghost4, 200);
    render(ghost5, 200);
    render(ghost6, 200);
    render(ghost7, 200);
    render(ghost8, 200);
    render(ghost9, 200);
    render(ghost10, 200);
    render(ghost11, 200);
    render(ghost12, 200);
    render(ghost13, 200);
    render(ghost14, 200);
    render(ghost15, 200);
    render(ghost16, 200);

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


   byte logowink2[8]={  
B11000000,
B11000000,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};

  for (int i = 1; i < times; i++) {  
    render(logowink0, 500);
    render(logowink1, 500);
    render(logowink0, 500);
    render(logowink2, 500);
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
  ijhacklogo();
  delay (1000);
  ghost(3);
  delay(500);
  invade(5);
  delay (1000);
  heart(4);
  delay (1000);
  invadesquid(5);
  delay (1000);
  ijlogowink(4);
  lc.clearDisplay(0);
  delay (1000);
  
}
