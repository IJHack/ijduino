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

uint8_t apple_x;
uint8_t apple_y;

uint8_t snake_x[70];
uint8_t snake_y[70];
uint8_t snake_len;
uint8_t snake_dir;
uint8_t make_longer = 0;

void show_field(bool apple_on)
{
  for (uint8_t i = 0; i < 8; i++)
    matrix[i] = 0;
  for (uint8_t i = 0; i < snake_len; i++)
    SETMAT(snake_x[i], snake_y[i]);
  if (apple_on)
    SETMAT(apple_x, apple_y);
  for (uint8_t x = 0; x < 8; x++)
    lc.setColumn(0, x, matrix[x]);
}

void place_random_apple()
{
  bool ok = false;
  while (!ok)
  {
    apple_x = random(8);
    apple_y = random(8);
    ok = true;
    for (uint8_t i = 0; i < snake_len; i++)
      if (snake_x[i] == apple_x && snake_y[i] == apple_y)
      {
        ok = false;
        break;
      }
  } 
}

void setup() {
  pinMode(POTPIN, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, brightness);
  lc.clearDisplay(0);
  Serial.begin(9600);
  Serial.println("Start");
  snake_len = 3;
  snake_x[0] = 4;
  snake_y[0] = 6;
  snake_x[1] = 5;
  snake_y[1] = 6;
  snake_x[2] = 6;
  snake_y[2] = 6;
  snake_dir = 0;  
  place_random_apple();
}


void loop() {
  int startp = analogRead(POTPIN);
  for (uint8_t i = 0; i < 5; i++)
  { 
    show_field(true);
    delay(100);
    show_field(false);
    delay(100);
  }
  if (make_longer > 0)
  {
    snake_len++;
    make_longer--;
  }
  
  for (uint8_t i = snake_len-1; i > 0; i--)
  {
    snake_x[i] = snake_x[i-1];
    snake_y[i] = snake_y[i-1];
  }
  int endp = analogRead(POTPIN);
  if (endp > startp + 50)
    snake_dir = (snake_dir + 1)%4;
  else if (endp < startp - 50)
    snake_dir = (snake_dir + 3)%4;  
  if (snake_dir == 0)
    snake_x[0]--;
  else if (snake_dir == 2)
    snake_x[0]++;
  else if (snake_dir == 1)
    snake_y[0]--;
  else if (snake_dir == 3)
    snake_y[0]++;

  if (   snake_x[0] < 0 || snake_x[0] > 7
      || snake_y[0] < 0 || snake_y[0] > 7)
  {
    delay(2000);
    setup();
  }
  for (uint8_t i = 1; i < snake_len; i++)
    if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
    {
      delay(2000);
      setup();
    }
  if (snake_x[0] == apple_x && snake_y[0] == apple_y)
  {
    make_longer = 2;
    place_random_apple();
  }
}
/*  
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
    int val = ;
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
*/
