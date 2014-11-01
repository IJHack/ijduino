//Vcc=5v grd=grd din=12 cs=10 clk=11
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
void writeArduinoOnMatrix() {
  /* here is the data for the characters */ 
  byte j[8]={
  
  B00110011,
  B01110011,
  B11100000,
  B11000000,
  B11000000,
  B11100000,
  B01111011,
  B00111011
  
  };
 
  lc.setRow(0,0,j[0]);
  lc.setRow(0,1,j[1]);
  lc.setRow(0,2,j[2]);
  lc.setRow(0,3,j[3]);
  lc.setRow(0,4,j[4]);
  lc.setRow(0,5,j[5]);
  lc.setRow(0,6,j[6]);
  lc.setRow(0,7,j[7]);
  delay(delaytime);
} 
 void writeArduinoOnMatrix1() {
   byte i[8]={
  
  B00110000,
  B01110000,
  B11100000,
  B11000000,
  B11000000,
  B11100000,
  B01111011,
  B00111011
  
  };


  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  lc.setRow(0,5,i[5]);
  lc.setRow(0,6,i[6]);
  lc.setRow(0,7,i[7]);
  delay(delaytime);
}

 void writeArduinoOnMatrix2() {
   byte i[8]={
  
  B00110011,
  B01110011,
  B11100000,
  B11000000,
  B11000000,
  B11100000,
  B01111000,
  B00111000
  
  };


  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  lc.setRow(0,5,i[5]);
  lc.setRow(0,6,i[6]);
  lc.setRow(0,7,i[7]);
  delay(delaytime);
}

void loop() { 
  writeArduinoOnMatrix();
  writeArduinoOnMatrix1();
  writeArduinoOnMatrix();  
  writeArduinoOnMatrix1();
  writeArduinoOnMatrix();
  writeArduinoOnMatrix2();

}
