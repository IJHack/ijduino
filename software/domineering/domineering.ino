/*
 * Domineering
 * 
 * Allows you to play the game domineering
 * (See https://en.wikipedia.org/wiki/Domineering)
 * with the use of a potentiometer. Player take
 * turns removing two blinking leds by turning the
 * potentiometer. After a user stops turning the
 * potentiometer the blinking slows down and removes
 * the two blinking leds, giving the turn to the
 * other player.
 * 
 * The size of the playing field can be changed by
 * modifying BOTTOM and TOP defines (taking into
 * account: (0 <= BOTTOM < TOP <= 8)
 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

#include "LedControl.h"
#include "Timer.h"

#define POTPIN A5 // Potentiometer

LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

#define brightness 1       //Values from 1 to 15 to set the brightness
uint8_t matrix[8];
#define MAT(X,Y) (matrix[X] & (1 << Y))
#define SETMAT(X,Y) matrix[X] |= (1 << Y)
#define RESETMAT(X,Y) matrix[X] &= ~(1 << Y)
uint8_t x_p[56];
uint8_t y_p[56];
#define BOTTOM 2
#define TOP 7

void showmat()
{
  for (uint8_t x = 0; x < 8; x++)
    lc.setColumn(0, x, matrix[x]);
}

void init_field()
{
  for (uint8_t i = 0; i < 8; i++)
    matrix[i] = 0;
  for (uint8_t y = BOTTOM; y < TOP; y++)
    for (uint8_t x = BOTTOM; x < TOP; x++)
      SETMAT(x,y);
  showmat();
}

bool vert_player = false;

void setup() {
  pinMode(POTPIN, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, brightness);
  lc.clearDisplay(0);
  Serial.begin(9600);
  Serial.println("Start");
  init_field();
}


void loop() {
  uint8_t len = 0;
  uint8_t v_x = 0;
  uint8_t v_y = 0;
  if (vert_player)
  {
    v_x = 1;
    for (uint8_t y = BOTTOM; y < TOP; y++)
      for (uint8_t x = BOTTOM; x < TOP-1; x++)
        if (MAT(x,y) != 0 && MAT(x+1, y) != 0)
        {
          x_p[len] = x;
          y_p[len] = y;
          len++;
        }
  }
  else
  {
    v_y = 1;
    for (uint8_t x = BOTTOM; x < TOP; x++)
      for (uint8_t y = BOTTOM; y < TOP-1; y++)
        if (MAT(x,y) != 0 && MAT(x, y+1) != 0)
        {
          x_p[len] = x;
          y_p[len] = y;
          len++;
        }
  }
  if (len == 0)
  {
    init_field();
    return;
  }

  int prev_pos = -1;
  bool moved = len == 1;
  int d = 50;
  for (;;)
  {
    int val = analogRead(POTPIN);
    int pos = (val - 12)/(1000/len);
    if (pos < 0)
      pos = 0;
    if (pos >= len)
      pos = len - 1;
    if (prev_pos != -1 && pos != prev_pos)
    {
      moved = true;
      d = 50;
    }
    else if (moved)
      d += 50;
    prev_pos = pos;
      
    RESETMAT(x_p[pos], y_p[pos]);
    RESETMAT(x_p[pos]+v_x, y_p[pos]+v_y);
    showmat();
  
    delay(d);

    if (d > 500)
      break;
      
    SETMAT(x_p[pos], y_p[pos]);
    SETMAT(x_p[pos]+v_x, y_p[pos]+v_y);
    showmat();
  
    delay(d);
  }
  vert_player = !vert_player;
}
