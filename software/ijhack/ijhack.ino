#include "LedControl.h"

LedControl lc=LedControl(20,5,21,1);

unsigned long delaytime=500;

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

void invade() {
   byte invade[8]={
B00100100,
B00100100,
B01111110,
B11011011,
B11111111,
B11111111,
B10100101,
B00100100};
  
  
 
  lc.setColumn(0,0,invade[7]);
  lc.setColumn(0,1,invade[6]);
  lc.setColumn(0,2,invade[5]);
  lc.setColumn(0,3,invade[4]);
  lc.setColumn(0,4,invade[3]);
  lc.setColumn(0,5,invade[2]);
  lc.setColumn(0,6,invade[1]);
  lc.setColumn(0,7,invade[0]);
  delay(delaytime);
  
  
}

void devade() {
   byte devade[8]={
B00100100,
B10100101,
B11111111,
B11011011,
B11111111,
B01111110,
B00100100,
B00100100};
  
  
 
  lc.setColumn(0,0,devade[7]);
  lc.setColumn(0,1,devade[6]);
  lc.setColumn(0,2,devade[5]);
  lc.setColumn(0,3,devade[4]);
  lc.setColumn(0,4,devade[3]);
  lc.setColumn(0,5,devade[2]);
  lc.setColumn(0,6,devade[1]);
  lc.setColumn(0,7,devade[0]);
  delay(delaytime);
  
  
}

void invadesquid() {
   byte invadesquid[8]={
B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B01011010,
B10000001,
B01000010};
  
  
 
  lc.setColumn(0,0,invadesquid[7]);
  lc.setColumn(0,1,invadesquid[6]);
  lc.setColumn(0,2,invadesquid[5]);
  lc.setColumn(0,3,invadesquid[4]);
  lc.setColumn(0,4,invadesquid[3]);
  lc.setColumn(0,5,invadesquid[2]);
  lc.setColumn(0,6,invadesquid[1]);
  lc.setColumn(0,7,invadesquid[0]);
  delay(delaytime);
  
  
}

void devadesquid() {
   byte devadesquid[8]={
B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01011010,
B10100101};
  
  
 
  lc.setColumn(0,0,devadesquid[7]);
  lc.setColumn(0,1,devadesquid[6]);
  lc.setColumn(0,2,devadesquid[5]);
  lc.setColumn(0,3,devadesquid[4]);
  lc.setColumn(0,4,devadesquid[3]);
  lc.setColumn(0,5,devadesquid[2]);
  lc.setColumn(0,6,devadesquid[1]);
  lc.setColumn(0,7,devadesquid[0]);
  delay(delaytime);
  
  
}



void ijlogo() {
  /* here is the data for the characters */ 
  byte logowink[8]={
B11000011,
B11000011,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};
  
  
 
  lc.setColumn(0,0,logowink[7]);
  lc.setColumn(0,1,logowink[6]);
  lc.setColumn(0,2,logowink[5]);
  lc.setColumn(0,3,logowink[4]);
  lc.setColumn(0,4,logowink[3]);
  lc.setColumn(0,5,logowink[2]);
  lc.setColumn(0,6,logowink[1]);
  lc.setColumn(0,7,logowink[0]);
  delay(delaytime);
} 
 void ijlogowink() {
   byte logowink1[8]={
  
B00000011,
B00000011,
B00000000,
B00000011,
B11000011,
B11100111,
B01111110,
B00111100};
  
  


  lc.setColumn(0,0,logowink1[7]);
  lc.setColumn(0,1,logowink1[6]);
  lc.setColumn(0,2,logowink1[5]);
  lc.setColumn(0,3,logowink1[4]);
  lc.setColumn(0,4,logowink1[3]);
  lc.setColumn(0,5,logowink1[2]);
  lc.setColumn(0,6,logowink1[1]);
  lc.setColumn(0,7,logowink1[0]);
  delay(delaytime);
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

  lc.setColumn(0,0,ij[7]);
  lc.setColumn(0,1,ij[6]);
  lc.setColumn(0,2,ij[5]);
  lc.setColumn(0,3,ij[4]);
  lc.setColumn(0,4,ij[3]);
  lc.setColumn(0,5,ij[2]);
  lc.setColumn(0,6,ij[1]);
  lc.setColumn(0,7,ij[0]);
  delay(delaytime);


//#  lc.setColumn(0,0,j[0]);
//  lc.setColumn(0,1,j[1]);
 // lc.setColumn(0,2,j[2]);
 // lc.setColumn(0,3,j[3]);
 // lc.setColumn(0,4,j[4]);
 // lc.setColumn(0,5,j[5]);
 // lc.setColumn(0,6,j[6]);
 // lc.setColumn(0,7,j[7]);
 // delay(delaytime);


  lc.setColumn(0,0,h[7]);
  lc.setColumn(0,1,h[6]);
  lc.setColumn(0,2,h[5]);
  lc.setColumn(0,3,h[4]);
  lc.setColumn(0,4,h[3]);
  lc.setColumn(0,5,h[2]);
  lc.setColumn(0,6,h[1]);
  lc.setColumn(0,7,h[0]);
  delay(delaytime);


  lc.setColumn(0,0,a[7]);
  lc.setColumn(0,1,a[6]);
  lc.setColumn(0,2,a[5]);
  lc.setColumn(0,3,a[4]);
  lc.setColumn(0,4,a[3]);
  lc.setColumn(0,5,a[2]);
  lc.setColumn(0,6,a[1]);
  lc.setColumn(0,7,a[0]);
  delay(delaytime);

 lc.setColumn(0,0,c[7]);
  lc.setColumn(0,1,c[6]);
  lc.setColumn(0,2,c[5]);
  lc.setColumn(0,3,c[4]);
  lc.setColumn(0,4,c[3]);
  lc.setColumn(0,5,c[2]);
  lc.setColumn(0,6,c[1]);
  lc.setColumn(0,7,c[0]);
  delay(delaytime);

  lc.setColumn(0,0,k[7]);
  lc.setColumn(0,1,k[6]);
  lc.setColumn(0,2,k[5]);
  lc.setColumn(0,3,k[4]);
  lc.setColumn(0,4,k[3]);
  lc.setColumn(0,5,k[2]);
  lc.setColumn(0,6,k[1]);
  lc.setColumn(0,7,k[0]);
  delay(delaytime);
}

void heart2() {
/* here is the data for the characters */
byte heart2[8]={B00000000,
B01100110,
B10011001,
B10000001,
B10000001,
B01000010,
B00100100,
B00011000};
lc.setColumn(0,0,heart2[7]);
lc.setColumn(0,1,heart2[6]);
lc.setColumn(0,2,heart2[5]);
lc.setColumn(0,3,heart2[4]);
lc.setColumn(0,4,heart2[3]);
lc.setColumn(0,5,heart2[2]);
lc.setColumn(0,6,heart2[1]);
lc.setColumn(0,7,heart2[0]);
delay(delaytime);
}
void heart1() {
/* here is the data for the characters */
byte heart[8]={
B00000000,
B01100110,
B11111111,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000};
lc.setColumn(0,0,heart[7]);
lc.setColumn(0,1,heart[6]);
lc.setColumn(0,2,heart[5]);
lc.setColumn(0,3,heart[4]);
lc.setColumn(0,4,heart[3]);
lc.setColumn(0,5,heart[2]);
lc.setColumn(0,6,heart[1]);
lc.setColumn(0,7,heart[0]);
delay(delaytime);
}



void loop() { 
  invade();
  devade();
  invade();
  devade();
  invade();
  devade();
  invade();
  devade();
  invade();
  devade();
  invadesquid();
  devadesquid();
  invadesquid();
  devadesquid();
  invadesquid();
  devadesquid();
  invadesquid();
  devadesquid();
  invadesquid();
  devadesquid();
  ijlogo();
  ijlogowink();
  ijlogo();
  ijlogowink();
  ijlogo();
  delay (1000);
  ijhacklogo();
  lc.clearDisplay(0);
  delay (1000);
  heart1();
  heart2();
  heart1();
  heart2();
  heart1();
  heart2();
  lc.clearDisplay(0);
  delay (1000);
  
}
