
#include "LedControl.h"
const int BUTTON_PIN = 9;


//#define POTPIN A0 // Potentiometer
long randNumber;
int oldrandNumber;


const int BAUD_RATE = 9600;


int old_button_state = LOW;
int current_button_state = LOW;


byte logo[] = {
  B11000011,
  B11000011,
  B00000000,
  B00000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100
};
byte D[] = {
  B11111100,
  B11111110,
  B11000111,
  B11000011,
  B11000011,
  B11000111,
  B11111110,
  B11111100
};
byte I[] = {
  B00111100,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,
  B00111100
};
byte C[] = {
  B01111110,
  B11111111,
  B11000011,
  B11000000,
  B11000000,
  B11000011,
  B11111111,
  B01111110
};
byte E[] = {
  B11111110,
  B11111110,
  B11000000,
  B11111000,
  B11111000,
  B11000000,
  B11111110,
  B11111110
};

byte one[] = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};
byte two[] = {
  B01100000,
  B01100000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000110,
  B00000110
};
byte three[] = {
  B01100000,
  B01100000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000110,
  B00000110
};
byte four[] = {
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110
};
byte five[] = {
  B01100110,
  B01100110,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B01100110,
  B01100110
};
byte six[] = {
  B01100110,
  B01100110,
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B01100110,
  B01100110
};


static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

void setSprite(byte *sprite) {
  for (int r = 0; r < 8; r++) {
    lc.setColumn(0, 7 - r, sprite[r]);
  }
}


void setup() {
  // The MAX72XX is in power-saving mode on startup,
  // we have to do a wakeup call
  //  pinMode(POTPIN, INPUT);
  randomSeed(analogRead(5));
  Serial.begin(BAUD_RATE);
  lc.shutdown(0, false);
  // Set the brightness to a medium values
  lc.setIntensity(0, 5);
  // and clear the display
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
  //#ifdef DEBUG
  Serial.println("GO");
  //#endif

  lc.setIntensity(0, 15);
  setSprite(logo);
  delay(500);
  lc.clearDisplay(0);
  lc.setIntensity(0, 13);
  setSprite(D);
  delay(500);
  lc.clearDisplay(0);
  lc.setIntensity(0, 11);
  setSprite(I);
  delay(500);
  lc.clearDisplay(0);
  lc.setIntensity(0, 9);
  setSprite(C);
  delay(500);
  lc.clearDisplay(0);
  lc.setIntensity(0, 7);
  setSprite(E);
  delay(500);
  lc.clearDisplay(0);
  lc.setIntensity(0, 5);
  delay(2000);
}


void loop() {
  int current_button_state = digitalRead(BUTTON_PIN);

  if (current_button_state == HIGH && old_button_state != current_button_state) {
    randomdice();
    delay(50);
  old_button_state = current_button_state;
  }
  else
    rolldice();
};


void rolldice() {
  int current_button_state = digitalRead(BUTTON_PIN);

  if (current_button_state == HIGH && old_button_state != current_button_state) {
    randomdice();
    delay(50);
  }
  // for (int i = 0; i <= 6; i++) {
  setSprite(one);
  delay(10);
  //lc.clearDisplay(0);
  setSprite(two);
  delay(10);
  //lc.clearDisplay(0);
  setSprite(three);
  delay(10);
  //lc.clearDisplay(0);
  setSprite(four);
  delay(10);
  //lc.clearDisplay(0);
  setSprite(five);
  delay(10);
  //lc.clearDisplay(0);
  setSprite(six);
  delay(10);
  //lc.clearDisplay(0);
  //  }
  old_button_state = current_button_state;
}




void randomdice() {
  lc.setIntensity(0, 15);
  randNumber = random(1, 6);
  Serial.println(randNumber);
  if (randNumber == oldrandNumber)
  {
    Serial.println("dubble roll");
  }

  if (randNumber == 1)
  {
    Serial.println("11");
    setSprite(one);
    //  delay(500);
    //  lc.clearDisplay(0);
  }
  if (randNumber == 2)
  {
    Serial.println("22");
    setSprite(two);
    //  delay(500);
    //  lc.clearDisplay(0);
  }
  if (randNumber == 3)
  {
    Serial.println("33");
    setSprite(three);
    //  delay(500);
    //  lc.clearDisplay(0);
  }
  if (randNumber == 4)
  {
    Serial.println("44");
    setSprite(four);
    // delay(500);
    // lc.clearDisplay(0);
  }
  if (randNumber == 5)
  { 
    Serial.println("55");
    setSprite(five);
    // delay(500);
    //  lc.clearDisplay(0);
  }
  if (randNumber == 6)
  {
    Serial.println("66");
    setSprite(six);
    //  delay(500);
    //  lc.clearDisplay(0);

  }
  delay(2000);
  lc.setIntensity(0, 5);

  //else;
  oldrandNumber = randNumber;


}
