#include "LedControl.h"

LedControl lc=LedControl(20,5,21,1);

int animations = 8;

int pullupPin = 13;
int buttonPin = 9;               // choose the input pin for the pushbutton

int anicount = 0;
int buttonState = 0;

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
  /* setup pins */
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pullupPin, OUTPUT);
  digitalWrite(pullupPin, LOW);
}

void loop() {
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    anicount++;
    if (anicount > animations) {
      anicount = 0;
    }
    anicounting();
  } else {
    anicounting();
  }
}

void anicounting() {
  switch (anicount) {
    case 0:
      ijhacklogo();
      break;
    case 1:
      ghost(1);
      break;
  }
  if (anicount == 2) {
    invade(1);
  }
  if (anicount == 3) {
    heart(1);
  }
  if (anicount == 4) {
    invadesquid(1);
  }
  if (anicount == 5) {
    jumper(1);
  }
  if (anicount == 6) {
    ijlogowink(1);
  }
  if (anicount == 7) {
    heartbeat(1);
  }
  if (anicount == 8) {
    eq(1);
  }
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

void invade(uint8_t times) {
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
  
  for (int i = 0; i < times; i++) {
    render(invade, 500);
    render(devade, 500);  
  }
}

void invadesquid(int8_t times) {
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

  for (int i = 0; i < times; i++) {
    render(invadesquid, 500);
    render(devadesquid, 500);  
  }
}

void ghost(uint8_t times) {

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


byte ghost9a[8]={
B00011100,
B00111110,
B01101101,
B01001001,
B01111111,
B01100011,
B01111111,
B01010101};

byte ghost9b[8]={
B00011100,
B00111110,
B01011011,
B01001001,
B01111111,
B01100011,
B01111111,
B01010101};

byte ghost9c[8]={
B00011100,
B00111110,
B01001001,
B01011011,
B01111111,
B01100011,
B01111111,
B01010101};

byte ghost9d[8]={
B00011100,
B00111110,
B01001001,
B01101101,
B01111111,
B01100011,
B01111111,
B01010101};


byte ghost9e[8]={
B00011100,
B00111110,
B01101101,
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

  for (int i = 0; i < times; i++) {
    render(ghost1, 200);
    render(ghost2, 200);  
    render(ghost3, 200);
    render(ghost4, 200);
    render(ghost5, 200);
    render(ghost6, 200);
    render(ghost7, 200);
    render(ghost8, 200);
    render(ghost9, 200);
    render(ghost9a, 200);
    render(ghost9b, 200);
    render(ghost9c, 200);
    render(ghost9d, 200);
    render(ghost9e, 200);
    render(ghost9a, 200);
    render(ghost9b, 200);
    render(ghost9c, 200);
    render(ghost9d, 200);
    render(ghost9e, 200);
    render(ghost9a, 200);
    render(ghost9b, 200);
    render(ghost9c, 200);
    render(ghost9d, 200);
    render(ghost9e, 200);
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

void ijlogowink(uint8_t times) {
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

   byte logowink3[8]={  
B11000011,
B11000011,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};

  for (int i = 0; i < times; i++) {  
    render(logowink0, 500);
    render(logowink1, 500);
    render(logowink0, 500);
    render(logowink2, 500);
    render(logowink0, 500);
    render(logowink3, 500);
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

void heart(uint8_t times) {
  
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

  for (int i = 0; i < times; i++) {
    render(heart1, 500);
    render(heart2, 500); 
  }
}

void jumper(uint8_t times) {
  byte jumpdown[8]={
B00111100,
B00111100,
B00011000,
B01111110,
B00011000,
B00011000,
B00100100,
B00100100};

  byte jumpup[8]={
B00111100,
B01011010,
B00111100,
B00011000,
B00011000,
B00100100,
B01000010,
B00000000};
 
  for (int i = 0; i < times; i++) {
    render(jumpdown, 500);
    render(jumpup, 500);  
  }
}

void heartbeat(uint8_t times) {
  byte heart1[8]={
B00000000,
B00000100,
B00000110,
B00000101,
B11100100,
B00010100,
B00001100,
B00000100};

  byte heart2[8]={
B00000000,
B00000010,
B00000011,
B00000010,
B11110010,
B00001010,
B00000110,
B00000010};

  byte heart3[8]={
B00000000,
B00000001,
B00000001,
B00000001,
B11111001,
B00000101,
B00000011,
B00000001};

  byte heart4[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B11111100,
B00000010,
B00000001,
B00000000};

  byte heart5[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B11111110,
B00000001,
B00000000,
B00000000};

  byte heart6[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B11111111,
B00000000,
B00000000,
B00000000};

  byte heart7[8]={
B00000000,
B00000000,
B00000000,
B10000000,
B01111111,
B00000000,
B00000000,
B00000000};

  byte heart8[8]={
B00000000,
B00000000,
B10000000,
B01000000,
B00111111,
B00000000,
B00000000,
B00000000};

  byte heart9[8]={
B00000000,
B10000000,
B11000000,
B10100000,
B10011111,
B10000000,
B10000000,
B10000000};

  byte heart10[8]={
B00000000,
B01000000,
B01100000,
B01010000,
B01001111,
B01000000,
B11000000,
B01000000};

  byte heart11[8]={
B00000000,
B00100000,
B00110000,
B00101000,
B00100111,
B10100000,
B01100000,
B00100000};

  byte heart12[8]={
B00000000,
B00010000,
B00011000,
B00010100,
B10010011,
B01010000,
B00110000,
B00010000};

  byte heart13[8]={
B00000000,
B00001000,
B00001100,
B00001010,
B11001001,
B00101000,
B00011000,
B00001000};

for (int i = 0; i < times; i++) {
    render(heart6, 100);  
    render(heart6, 100);  
    render(heart7, 100);  
    render(heart8, 100);  
    render(heart9, 100);  
    render(heart10, 100);  
    render(heart11, 100);  
    render(heart12, 100);  
    render(heart13, 100);  
    render(heart1, 100);
    render(heart2, 100);  
    render(heart3, 100);  
    render(heart4, 100);  
    render(heart5, 100);
    render(heart6, 100);  
    render(heart6, 100);  
  }
}

void eq(uint8_t times) {
  byte eq1[8]={
B00000000,
B00001100,
B11001100,
B11001100,
B11111100,
B11111100,
B11111111,
B11111111};

  byte eq2[8]={
B00000000,
B00001100,
B11001100,
B11001100,
B11111100,
B11111100,
B11111111,
B11111111};

  byte eq3[8]={
B00000000,
B00001100,
B11001100,
B11001100,
B11111100,
B11111100,
B11111111,
B11111111};

  byte eq4[8]={
B00000000,
B00000000,
B00001100,
B11001100,
B11001100,
B11111111,
B11111111,
B11111111};

  byte eq5[8]={
B00000000,
B00000000,
B00000000,
B00001100,
B11001111,
B11001111,
B11111111,
B11111111};

  byte eq6[8]={
B00000000,
B00000000,
B00000000,
B00000011,
B00001111,
B11001111,
B11001111,
B11111111};

  byte eq7[8]={
B00000000,
B00000000,
B00000011,
B00000011,
B00001111,
B00001111,
B11001111,
B11001111};

  byte eq8[8]={
B00000000,
B00000000,
B00000000,
B00000011,
B00000011,
B00001111,
B00001111,
B11111111};

  byte eq9[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000011,
B00000011,
B00111111,
B11111111};

  byte eq10[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000011,
B00000011,
B00111111,
B11111111};

  byte eq11[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000011,
B00001111,
B11001111,
B11111111};

  byte eq12[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00001100,
B11001111,
B11111111,
B11111111};

  byte eq13[8]={
B00000000,
B00000000,
B00000000,
B00001100,
B11001100,
B11111111,
B11111111,
B11111111};

  byte eq14[8]={
B00000000,
B00000000,
B00001100,
B11001100,
B11001100,
B11111111,
B11111111,
B11111111};

  byte eq15[8]={
B00000000,
B00001100,
B11001100,
B11001100,
B11001100,
B11111100,
B11111111,
B11111111};

  for (int i = 0; i < times; i++) {
    render(eq1, 50);
    render(eq2, 50);  
    render(eq3, 50);  
    render(eq4, 50);  
    render(eq5, 50);  
    render(eq6, 50);  
    render(eq7, 50);  
    render(eq8, 50);  
    render(eq9, 50);  
    render(eq10, 50);  
    render(eq11, 50);  
    render(eq12, 50);  
    render(eq13, 50);  
    render(eq14, 50);  
    render(eq15, 50);     
  }
}
