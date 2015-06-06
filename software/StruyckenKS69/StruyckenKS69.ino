//After Komputerstrukturen 1969/70 by Peter Struycken with MAX7219

/*
     * dataPin		pin on the Arduino where data gets shifted out
     * clockPin		pin for the clock
     * csPin		pin for selecting the device
     * numDevices	maximum number of devices that can be controled
LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
*/

#include "LedControl.h"     //Imports the library

static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

#define brightness 1       //Values from 1 to 15 to set the brightness
int analogPin = 0;          //analogPin for the random seed data

unsigned char world[8][8];
unsigned char state[4][4];
int prev_i;
int prev_j;

void setWorld()
{
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
       world[i][j] = 0;

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    {
      int i2 = i * 2;
      int j2 = j * 2;
      unsigned char s = state[i][j];
      if (s == 0)
        world[i2][j2] = 1;
      else if (s == 1)
        world[i2][j2+1] = 1;
      else if (s == 2)
        world[i2+1][j2+1] = 1;
      else
        world[i2+1][j2] = 1;
    }
  for (int i = 0; i < 8; i++)
  {
    int r = 0;
    for (int j = 0; j < 8; j++)
      r = (r << 1) | world[i][j];
    lc.setColumn(0, 7-i, r);
  }
}

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, brightness);
  lc.clearDisplay(0);
  randomSeed(analogRead(analogPin));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      state[i][j] = random(4);
  setWorld();
  prev_i = 0;
  prev_j = 0;
}

/*******************************************************************************/

void loop()
{
  delay(300);

  int i = random(3);
  if (i >= prev_i)
    i++;
  int j = random(3);
  if (j >= prev_j)
    j++;
  int old_s = state[i][j];
  state[i][j] = (old_s + (random(2) ? 1 : 3)) % 4; 
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (   state[i][j] == 2 && state[i][j+1] == 3
          && state[i+1][j+1] == 0 && state[i+1][j] == 1)
      {
        state[i][j] = old_s;
        return;
      }
  setWorld();
  delay(1000);
  prev_i = i;
  prev_j = j;

}
