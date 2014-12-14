/**
*  Play pong on an 8x8 matrix
*
*    0 1 2 3 4 5 6 7
*  0
*  1
*  2      7 0 1
*  3      6 X 2 (directions)
*  4      5 4 3
*  5
*  6
*  7    [pad]
*
*
*  Based on code from http://www.itopen.it/2012/03/09/arduino-pong-with-8x8-led-matrix-and-max7219/
*
*/

static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

#include "LedControl.h"
#include "Timer.h"


#define POTPIN A5 // Potentiometer
#define PADSIZE 2
#define BALL_DELAY 200
#define GAME_DELAY 10
#define BOUNCE_VERTICAL 1
#define BOUNCE_HORIZONTAL -1
#define NEW_GAME_ANIMATION_SPEED 50
#define HIT_NONE 0
#define HIT_CENTER 1
#define HIT_LEFT 2
#define HIT_RIGHT 3


//#define DEBUG 1


byte sad[] = {
  B11000011,
  B11000011,
  B00000000,
  B00000000,
  B00111100,
  B01111110,
  B11100111,
  B11000011
};

byte smile[] = {
  B11000011,
  B11000011,
  B00000000,
  B00000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100
};

byte P[] = {
  B01111110,
  B11111111,
  B11000011,
  B11000011,
  B11111111,
  B11111110,
  B11000000,
  B11000000
};
byte O[] = {
  B01111110,
  B11111111,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11111111,
  B01111110
};
byte N[] = {
  B11000011,
  B11100011,
  B11110011,
  B11111011,
  B11011111,
  B11001111,
  B11000111,
  B11000011
};
byte G[] = {
  B01111110,
  B11111111,
  B11000011,
  B11000000,
  B11001111,
  B11000011,
  B11111111,
  B01111110
};
Timer timer;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

byte direction; // Wind rose, 0 is north
int xball;
int yball;
int yball_prev;
byte xpad;
int ball_timer;

void setSprite(byte *sprite) {
  for (int r = 0; r < 8; r++) {
    lc.setColumn(0, 7 - r, sprite[r]);
  }
}


void newGame() {

  setSprite(smile);
  delay(500);
  lc.clearDisplay(0);
  setSprite(P);
  delay(500);
  lc.clearDisplay(0);
  setSprite(O);
  delay(500);
  lc.clearDisplay(0);
  setSprite(N);
  delay(500);
  lc.clearDisplay(0);
  setSprite(G);
  delay(500);
  
  lc.clearDisplay(0);
// initial position
xball = random(1, 7);
yball = 1;
direction = random(3, 6); // Go south
for (int r = 0; r < 8; r++) {
for (int c = 0; c < 8; c++) {
lc.setLed(0, c, r, HIGH);
delay(NEW_GAME_ANIMATION_SPEED);
}
}
//setSprite(smile);
//
//delay(1500);
//
lc.clearDisplay(0);
}



void setPad() {
  xpad = map(analogRead(POTPIN), 0, 1020, 8 - PADSIZE, 0);
}

void debug(const char* desc) {
#ifdef DEBUG
  Serial.print(desc);
  Serial.print(" XY: ");
  Serial.print(xball);
  Serial.print(", ");
  Serial.print(yball);
  Serial.print(" XPAD: ");
  Serial.print(xpad);
  Serial.print(" DIR: ");
  Serial.println(direction);
#endif
}

int checkBounce() {
  if (!xball || !yball || xball == 7 || yball == 6) {
    int bounce = (yball == 0 || yball == 6) ? BOUNCE_HORIZONTAL : BOUNCE_VERTICAL;
#ifdef DEBUG
    debug(bounce == BOUNCE_HORIZONTAL ? "HORIZONTAL" : "VERTICAL");
#endif
    return bounce;
  }
  return 0;
}

int getHit() {
  if (yball != 6 || xball < xpad || xball > xpad + PADSIZE) {
    return HIT_NONE;
  }
  if (xball == xpad + PADSIZE / 2) {
    return HIT_CENTER;
  }
  return xball < xpad + PADSIZE / 2 ? HIT_LEFT : HIT_RIGHT;
}

bool checkLoose() {
  return yball == 6 && getHit() == HIT_NONE;
}

void moveBall() {
  debug("MOVE");
  int bounce = checkBounce();
  if (bounce) {
    switch (direction) {
      case 0:
        direction = 4;
        break;
      case 1:
        direction = (bounce == BOUNCE_VERTICAL) ? 7 : 3;
        break;
      case 2:
        direction = 6;
        break;
      case 6:
        direction = 2;
        break;
      case 7:
        direction = (bounce == BOUNCE_VERTICAL) ? 1 : 5;
        break;
      case 5:
        direction = (bounce == BOUNCE_VERTICAL) ? 3 : 7;
        break;
      case 3:
        direction = (bounce == BOUNCE_VERTICAL) ? 5 : 1;
        break;
      case 4:
        direction = 0;
        break;
    }
    debug("->");
  }

  // Check hit: modify direction is left or right
  switch (getHit()) {
    case HIT_LEFT:
      if (direction == 0) {
        direction =  7;
      } else if (direction == 1) {
        direction = 0;
      }
      break;
    case HIT_RIGHT:
      if (direction == 0) {
        direction = 1;
      } else if (direction == 7) {
        direction = 0;
      }
      break;
  }

  // Check orthogonal directions and borders ...
  if ((direction == 0 && xball == 0) || (direction == 4 && xball == 7)) {
    direction++;
  }
  if (direction == 0 && xball == 7) {
    direction = 7;
  }
  if (direction == 4 && xball == 0) {
    direction = 3;
  }
  if (direction == 2 && yball == 0) {
    direction = 3;
  }
  if (direction == 2 && yball == 6) {
    direction = 1;
  }
  if (direction == 6 && yball == 0) {
    direction = 5;
  }
  if (direction == 6 && yball == 6) {
    direction = 7;
  }

  // "Corner" case
  if (xball == 0 && yball == 0) {
    direction = 3;
  }
  if (xball == 0 && yball == 6) {
    direction = 1;
  }
  if (xball == 7 && yball == 6) {
    direction = 7;
  }
  if (xball == 7 && yball == 0) {
    direction = 5;
  }

  yball_prev = yball;
  if (2 < direction && direction < 6) {
    yball++;
  } else if (direction != 6 && direction != 2) {
    yball--;
  }
  if (0 < direction && direction < 4) {
    xball++;
  } else if (direction != 0 && direction != 4) {
    xball--;
  }
  xball = max(0, min(7, xball));
  yball = max(0, min(6, yball));
  debug("AFTER MOVE");
}

void gameOver() {
  setSprite(sad);
  delay(500);
  lc.clearDisplay(0);
  delay(500);
  setSprite(sad);
  delay(500);
  lc.clearDisplay(0);
  delay(500);
  setSprite(sad);
  delay(1500);
  lc.clearDisplay(0);
}

void drawGame() {
  if (yball_prev != yball) {
    lc.setColumn(0, 7 - yball_prev, 0);
  }
  lc.setColumn(0, 7 - yball, byte(1 << (xball)));
  byte padmap = byte(0xFF >> (8 - PADSIZE) << xpad) ;
#ifdef DEBUG
  //Serial.println(padmap, BIN);
#endif
  lc.setColumn(0, 0, padmap);
}

void setup() {
  // The MAX72XX is in power-saving mode on startup,
  // we have to do a wakeup call
  pinMode(POTPIN, INPUT);

  lc.shutdown(0, false);
  // Set the brightness to a medium values
  lc.setIntensity(0, 8);
  // and clear the display
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Pong");
#endif
  newGame();
  ball_timer = timer.every(BALL_DELAY, moveBall);
}


void loop() {
  timer.update();
  // Move pad
  setPad();
#ifdef DEBUG
  Serial.println(xpad);
#endif
  // Update screen
  drawGame();
  if (checkLoose()) {
    debug("LOOSE");
    gameOver();
    newGame();
  }
  delay(GAME_DELAY);
}
