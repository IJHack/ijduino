
/*                            IJduino 1.0
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

/* using VCC, GND, DIN 21, CS 21, CLK 5 for the MAX7219 */
LedControl lc=LedControl(20,5,21,1);

int lowPin = 11;             /* ground pin for the buton ;-) */
int buttonPin = 9;           /* choose the input pin for the pushbutton */

int animations = 11;         /* the number of animations we have */

int lastButtonState = LOW;   /* the previous reading from the input pin */
long lastDebounceTime = 0;   /* the last time the output pin was toggled */
long debounceDelay = 50;     /* the debounce time; increase if the output flickers */
int anicount = 0;
int buttonState = LOW;

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
  pinMode(lowPin, OUTPUT);
  digitalWrite(lowPin, LOW);
}

void loop() {
  switch (anicount) {
    case 0:
      ijhacklogo();
      break;
    case 1:
      ghost();
      break;
    case 2:
      invade();
      break;
    case 3:
      heart();
      break;
    case 4:
      invadesquid();
      break;
    case 5:
      jumper();
      break;
    case 6:
      ijlogowink();
      break;
    case 7:
      heartbeat();
      break;
    case 8:
      eq();
      break;
    case 9:
      invaderagain();
      break;
    case 10:
      pong();
      break;
    case 11:
      snake();
      break;
  }
}

bool render(byte* animation, int delaytime) {
  lc.setColumn(0,0,animation[7]);
  lc.setColumn(0,1,animation[6]);
  lc.setColumn(0,2,animation[5]);
  lc.setColumn(0,3,animation[4]);
  lc.setColumn(0,4,animation[3]);
  lc.setColumn(0,5,animation[2]);
  lc.setColumn(0,6,animation[1]);
  lc.setColumn(0,7,animation[0]);
  
  long startTime = millis();
  while ((startTime + delaytime) > millis()){
  
    // read the state of the switch into a local variable:
    int reading = digitalRead(buttonPin);

    // check to see if you just pressed the button 
    // (i.e. the input went from HIGH to LOW),  and you've waited 
    // long enough since the last press to ignore any noise:  
  
    // If the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    } 
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (reading != buttonState) {
        buttonState = reading;
  
        // only toggle the animation if the new button state is HIGH
        if (buttonState == LOW) {
          anicount++;
          if (anicount > animations) {
            anicount = 0;
          }
          return true;
        }
      }
    }
  
    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastButtonState = reading;
  }
  return false;  /* don't skip the rest */
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

byte devade[8]={
B00100100,
B10100101,
B11111111,
B11011011,
B11111111,
B01111110,
B00100100,
B00100100};
  
  bool skip = render(invade, 500);
  if (skip) {
    return;
  }
  render(devade, 500);
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

   byte devadesquid[8]={
B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01011010,
B10100101};

  bool skip = render(invadesquid, 500);
  if (skip) {
    return;
  }
  render(devadesquid, 500);  
}

void ghost() {

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

  bool skip;
  skip = render(ghost1, 200);
  if (skip) {
    return;
  }
  skip = render(ghost2, 200);  
  if (skip) {
    return;
  }
  skip = render(ghost3, 200);
  if (skip) {
    return;
  }
  skip = render(ghost4, 200);
  if (skip) {
    return;
  }
  skip = render(ghost5, 200);
  if (skip) {
    return;
  }
  skip = render(ghost6, 200);
  if (skip) {
    return;
  }
  skip = render(ghost7, 200);
  if (skip) {
    return;
  }
  skip = render(ghost8, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9a, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9b, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9c, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9d, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9e, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9a, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9b, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9c, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9d, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9e, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9a, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9b, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9c, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9d, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9e, 200);
  if (skip) {
    return;
  }
  skip = render(ghost9, 200);
  if (skip) {
    return;
  }
  skip = render(ghost10, 200);
  if (skip) {
    return;
  }
  skip = render(ghost11, 200);
  if (skip) {
    return;
  }
  skip = render(ghost12, 200);
  if (skip) {
    return;
  }
  skip = render(ghost13, 200);
  if (skip) {
    return;
  }
  skip = render(ghost14, 200);
  if (skip) {
    return;
  }
  skip = render(ghost15, 200);
  if (skip) {
    return;
  }
  render(ghost16, 200);
}

void ijlogowink() {
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

  bool skip;
  skip = render(logowink0, 500);
  if (skip) {
    return;
  }
  skip = render(logowink1, 500);
  if (skip) {
    return;
  }
  skip = render(logowink0, 500);
  if (skip) {
    return;
  }  
  skip = render(logowink2, 500);
  if (skip) {
    return;
  }
  skip = render(logowink0, 500);
  if (skip) {
    return;
  }
  skip = render(logowink3, 500);  
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

  bool skip;
  skip = render(ij, 500);
  if (skip) {
    return;
  }
  skip = render(h, 500);
  if (skip) {
    return;
  }
  skip = render(a, 500);
  if (skip) {
    return;
  }
  skip = render(c, 500);
  if (skip) {
    return;
  }
  render(k, 500);
}

void heart() {
  
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

  bool skip = render(heart1, 500);
  if (skip) {
    return;
  }
  render(heart2, 500); 
}

void jumper() {
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

  bool skip = render(jumpdown, 500);
  if (skip) {
    return;
  }
  render(jumpup, 500);  
}

void heartbeat() {
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

  bool skip;
  skip = render(heart6, 100);  
  if (skip) {
    return;
  }
  skip = render(heart6, 100);  
  if (skip) {
    return;
  }
  skip = render(heart7, 100);  
  if (skip) {
    return;
  }
  skip = render(heart8, 100);  
  if (skip) {
    return;
  }
  skip = render(heart9, 100);  
  if (skip) {
    return;
  }
  skip = render(heart10, 100);  
  if (skip) {
    return;
  }
  skip = render(heart11, 100);  
  if (skip) {
    return;
  }
  skip = render(heart12, 100);  
  if (skip) {
    return;
  }
  skip = render(heart13, 100);  
  if (skip) {
    return;
  }
  skip = render(heart1, 100);
  if (skip) {
    return;
  }
  skip = render(heart2, 100);  
  if (skip) {
    return;
  }
  skip = render(heart3, 100);  
  if (skip) {
    return;
  }
  skip = render(heart4, 100);  
  if (skip) {
    return;
  }
  skip = render(heart5, 100);
  if (skip) {
    return;
  }
  render(heart6, 100);  
}

void eq() {
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

  bool skip;
  skip = render(eq1, 50);
  if (skip) {
    return;
  }
  skip = render(eq2, 50);  
  if (skip) {
    return;
  }
  skip = render(eq3, 50);  
  if (skip) {
    return;
  }
  skip = render(eq4, 50);  
  if (skip) {
    return;
  }
  skip = render(eq5, 50);  
  if (skip) {
    return;
  }
  skip = render(eq6, 50);  
  if (skip) {
    return;
  }
  skip = render(eq7, 50);  
  if (skip) {
    return;
  }
  skip = render(eq8, 50);  
  if (skip) {
    return;
  }
  skip = render(eq9, 50);  
  if (skip) {
    return;
  }
  skip = render(eq10, 50);  
  if (skip) {
    return;
  }
  skip = render(eq11, 50);  
  if (skip) {
    return;
  }
  skip = render(eq12, 50);  
  if (skip) {
    return;
  }
  skip = render(eq13, 50);  
  if (skip) {
    return;
  }
  skip = render(eq14, 50);  
  if (skip) {
    return;
  }
  render(eq15, 50);     
}



void invaderagain() {
  byte invader1[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};
 
  byte invader2[8]={
B00000000,
B00000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000};
 
  byte invader3[8]={
B00000000,
B10000000,
B11000000,
B11000000,
B01000000,
B01000000,
B01000000,
B11000000};

  byte invader4[8]={
B10000000,
B11000000,
B01100000,
B11100000,
B10100000,
B00100000,
B00100000,
B01100000};

  byte invader5[8]={
B01000000,
B11100000,
B10110000,
B11110000,
B01010000,
B10010000,
B00010000,
B00110000};

  byte invader6[8]={
B00100000,
B11110000,
B11011000,
B11111000,
B00101000,
B11001000,
B00001000,
B00011000};

  byte invader7[8]={
B10010000,
B11111000,
B01101100,
B11111100,
B10010100,
B01100100,
B00000100,
B00001100};

   byte invader8[8]={
B01001000,
B11111100,
B10110110,
B11111110,
B01001010,
B00110010,
B00000010,
B10000110};

   byte invader9[8]={
B00100100,
B01111110,
B11011011,
B11111111,
B10100101,
B10011001,
B10000001,
B11000011};

   byte invader9a[8]={
B00100100,
B00011000,
B01111110,
B11011011,
B11111111,
B11011011,
B10011001,
B11000011};

   byte invader10[8]={
B00010010,
B00111111,
B01101101,
B01111111,
B01010010,
B01001100,
B01000000,
B01100001};


   byte invader11[8]={
B00001001,
B00011111,
B00110110,
B00111111,
B00101001,
B00100110,
B00100000,
B00110000};



   byte invader12[8]={
B00000100,
B00001111,
B00011011,
B00011111,
B00010100,
B00010011,
B00010000,
B00011000};

   byte invader13[8]={
B00000010,
B00000111,
B00001101,
B00001111,
B00001010,
B00001001,
B00001000,
B00001100};


   byte invader14[8]={
B00000001,
B00000011,
B00000110,
B00000111,
B00000101,
B00000100,
B00000100,
B00000110};

   byte invader15[8]={
B00000000,
B00000001,
B00000011,
B00000011,
B00000010,
B00000010,
B00000010,
B00000011};

   byte invader16[8]={
B00000000,
B00000000,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001};

  bool skip;
  skip = render(invader1, 200);
  if (skip) {
    return;
  }
  skip = render(invader2, 200);
  if (skip) {
    return;
  }
  skip = render(invader3, 200);
  if (skip) {
    return;
  }
  skip = render(invader4, 200);
  if (skip) {
    return;
  }
  skip = render(invader5, 200);
  if (skip) {
    return;
  }
  skip = render(invader6, 200);
  if (skip) {
    return;
  }
  skip = render(invader7, 200);
  if (skip) {
    return;
  }
  skip = render(invader8, 200);
  if (skip) {
    return;
  }
  skip = render(invader9, 200);
  if (skip) {
    return;
  }
  skip = render(invader9a, 200);
  if (skip) {
    return;
  }
  skip = render(invader9, 200);
  if (skip) {
    return;
  }
  skip = render(invader9a, 200);
  if (skip) {
    return;
  }
  skip = render(invader9, 200);
  if (skip) {
    return;
  }
  skip = render(invader9a, 200);
  if (skip) {
    return;
  }
  skip = render(invader9, 200);
  if (skip) {
    return;
  }
  skip = render(invader10, 200);
  if (skip) {
    return;
  }
  skip = render(invader11, 200);
  if (skip) {
    return;
  }
  skip = render(invader12, 200);
  if (skip) {
    return;
  }
  skip = render(invader13, 200);
  if (skip) {
    return;
  }
  skip = render(invader14, 200);
  if (skip) {
    return;
  }
  skip = render(invader15, 200);
  if (skip) {
    return;
  }
  skip = render(invader16, 200);
  if (skip) {
    return;
  }
  render(invader1, 200);
}


void pong() {
  byte pong1[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00011100};

  byte pong2[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000001,
B00000000,
B00001110};

  byte pong3[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000010,
B00000111};


  byte pong4[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000100,
B00000000,
B00000111};

  byte pong5[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00001000,
B00000000,
B00000000,
B00000111};

  byte pong6[8]={
B00111000,
B00000000,
B00000000,
B00010000,
B00000000,
B00000000,
B00000000,
B00001110};

  byte pong7[8]={
B01110000,
B00000000,
B00100000,
B00000000,
B00000000,
B00000000,
B00000000,
B00001110};

  byte pong8[8]={
B11100000,
B01000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00011100};

  byte pong9[8]={
B11100000,
B00000000,
B00100000,
B00000000,
B00000000,
B00000000,
B00000000,
B00011100};

  byte pong10[8]={
B11100000,
B00000000,
B00000000,
B00010000,
B00000000,
B00000000,
B00000000,
B00111000};

  byte pong11[8]={
B01110000,
B00000000,
B00000000,
B00000000,
B00001000,
B00000000,
B00000000,
B01110000};

  byte pong12[8]={
B01110000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000100,
B00000000,
B00111000};

  byte pong13[8]={
B01110000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000010,
B00011100};

  byte pong14[8]={
B00111000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00011101};

  bool skip;
  skip = render(pong1, 200);  
  if (skip) {
    return;
  }
  skip = render(pong2, 200);  
  if (skip) {
    return;
  }
  skip = render(pong3, 200);  
  if (skip) {
    return;
  }
  skip = render(pong4, 200);  
  if (skip) {
    return;
  }
  skip = render(pong5, 200);  
  if (skip) {
    return;
  }
  skip = render(pong6, 200);
  if (skip) {
    return;
  }
  skip = render(pong7, 200);  
  if (skip) {
    return;
  }
  skip = render(pong8, 200);  
  if (skip) {
    return;
  }
  skip = render(pong9, 200);  
  if (skip) {
    return;
  }
  skip = render(pong10, 200);  
  if (skip) {
    return;
  }
  skip = render(pong11, 200);  
  if (skip) {
    return;
  }
  skip = render(pong12, 200);
  if (skip) {
    return;
  }
  skip = render(pong13, 200);  
  if (skip) {
    return;
  }
  skip = render(pong14, 200);  
}


void snake() {
  byte snake1[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};

  byte snake2[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000001,
B00000000};

  byte snake3[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000011,
B00000000};

  byte snake4[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000111,
B00000000};

  byte snake5[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00001110,
B00000000};

  byte snake6[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00011100,
B00000000};

  byte snake7[8]={
B00000000,
B00000000,
B01000000,
B00000000,
B00000000,
B00000000,
B00111000,
B00000000};

  byte snake8[8]={
B00000000,
B00000000,
B01000000,
B00000000,
B00000000,
B00100000,
B00110000,
B00000000};

  byte snake9[8]={
B00000000,
B00000000,
B01000000,
B00000000,
B00100000,
B00100000,
B00100000,
B00000000};

  byte snake10[8]={
B00000000,
B00000000,
B01000000,
B00100000,
B00100000,
B00100000,
B00000000,
B00000000};

  byte snake11[8]={
B00000000,
B00000000,
B01100000,
B00100000,
B00100000,
B00000000,
B00000000,
B00000000};

  byte snake12[8]={
B00000000,
B01000000,
B01100000,
B00100000,
B00100000,
B00000000,
B00000000,
B00000000};

  byte snake13[8]={
B01000000,
B01000000,
B01100000,
B00100000,
B00000000,
B00000000,
B00000000,
B00000000};

  byte snake14[8]={
B01100000,
B01000000,
B01100000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};

  byte snake15[8]={
B01110000,
B01000000,
B01000000,
B00000000,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake16[8]={
B01111000,
B01000000,
B00000000,
B00000000,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake17[8]={
B01111100,
B00000000,
B00000000,
B00000000,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake18[8]={
B00111100,
B00000100,
B00000000,
B00000000,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake19[8]={
B00011100,
B00000100,
B00000100,
B00000000,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake20[8]={
B00001100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000000,
B00000000,
B00000000};

  byte snake21[8]={
B00001100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000000,
B00000000};

  byte snake22[8]={
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000000};

  byte snake23[8]={
B00000000,
B00000100,
B00000100,
B00100100,
B00000100,
B00000100,
B00001100,
B00000000};

  byte snake24[8]={
B00000000,
B00000000,
B00000100,
B00100100,
B00000100,
B00000100,
B00011100,
B00000000};

  byte snake25[8]={
B00000000,
B00000000,
B00000000,
B00100100,
B00000100,
B00010100,
B00011100,
B00000000};

  byte snake26[8]={
B00000000,
B00000000,
B00000000,
B00100000,
B00010100,
B00010100,
B00011100,
B00000000};

  byte snake27[8]={
B00000000,
B00000000,
B00000000,
B00100000,
B00110000,
B00010100,
B00011100,
B00000000};

  byte snake28[8]={
B00000000,
B00000000,
B00000000,
B01100000,
B00110000,
B00010100,
B00011100,
B00000000};

  byte snake29[8]={
B00000000,
B00000000,
B00000000,
B11100000,
B00110000,
B00010100,
B00011100,
B00000000};


  byte snake30[8]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};



  render(snake1, 200);
  render(snake2, 200);
  render(snake3, 200);
  render(snake4, 200);
  render(snake5, 200);
  render(snake6, 200);
  render(snake7, 200);
  render(snake8, 200);
  render(snake9, 200);
  render(snake10, 200);
  render(snake11, 200);
  render(snake12, 200);
  render(snake13, 200);
  render(snake14, 200);
  render(snake15, 200);
  render(snake16, 200);
  render(snake17, 200);
  render(snake18, 200);
  render(snake19, 200);
  render(snake20, 200);
  render(snake21, 200);
  render(snake22, 200);
  render(snake23, 200);
  render(snake24, 200);
  render(snake25, 200);
  render(snake26, 200);
  render(snake27, 200);  
  render(snake28, 200);
  render(snake29, 200);
  render(snake30, 200);
  render(snake29, 200);
  render(snake30, 200);
  render(snake29, 200);
  render(snake30, 200);

}



