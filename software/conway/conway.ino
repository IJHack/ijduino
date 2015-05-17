//Game of Life with MAX7219

// BROKEN SOMEHOW

/*

     * dataPin		pin on the Arduino where data gets shifted out
     * clockPin		pin for the clock
     * csPin		pin for selecting the device
     * numDevices	maximum number of devices that can be controled
LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
*/
/*******************************************************************************/

#include "LedControl.h"     //Imports the library

static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

#define SIZEX 8             //Sets the X axis size
#define SIZEY 8             //Sets the Y axis size
#define reseedrate 30       //Sets the rate the world is re-seeded
#define brightness 15       //Values from 1 to 15 to set the brightness
long density = 35;          //Sets density % during seeding
unsigned long delaytime = 150; //Sets the time each generation is shown
int generation = 0;         //Counter for re-seeding
int analogPin = 0;          //analogPin for the random seed data

unsigned char world1[8][8] = {
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0},
  {0, 1, 0, 1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0, 1, 1, 0},
  {0, 1, 1, 0, 0, 1, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 0},
  {0, 0, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0}
};
unsigned char world2[8][8];

/*******************************************************************************/
/* display cells */

void display_cells(unsigned char world1[8][8])
{
  int i, j;
  for (i = 0; i < SIZEX; i++)
  {
    for (j = 0; j < SIZEY; j++)
    {
      lc.setLed(0, i, j, world1[i][j]);

    }
  }
}

/*******************************************************************************/
/* compute previous generation*/

void previous_generation(unsigned char world1[8][8], unsigned char world2[8][8])
{
  int i, j;

  for (i = 0; i < SIZEX; i++)
  {
    for (j = 0; j < SIZEY; j++)
    {
      world2[i][j] = world1[i][j];
    }
  }
}

/*******************************************************************************/
/* compute next generation */

void next_generation(unsigned char world1[8][8], unsigned char world2[8][8])
{
  int i, j;

  for (i = 0; i < SIZEX; i++)
  {
    for (j = 0; j < SIZEY; j++)
    {
      world1[i][j] = world2[i][j];
    }
  }
}


/*******************************************************************************/
/* compute neighboring cells */

void neighbours(unsigned char world1[8][8], unsigned char world2[8][8])
{
  int a = 0;

  for (int i = 0; i < SIZEX; i++)
  {
    int above = (i + SIZEX - 1) % SIZEX;
    int below = (i + 1) % SIZEX;

    for (int j = 0; j < SIZEY; j++)
    {
      int left = (j + SIZEY - 1) % SIZEY;
      int right = (j + 1) % SIZEY;

      a += world1[above][left];
      a += world1[above][j];
      a += world1[above][right];
      a += world1[i][left];
      a += world1[i][right];
      a += world1[below][left];
      a += world1[below][j];
      a += world1[below][right];

      if ((world1[i][j] == 0) && (a == 3)) {
        world2[i][j] = 1;
      }
      if ((world1[i][j] == 1) && ((a == 2) || (a == 3))) {
        world2[i][j] = 1;
      }
      if ((world1[i][j] == 1) && ((a == 1) || (a == 0) || (a > 3))) {
        world2[i][j] = 0;
      }
    }
  }
}

/*******************************************************************************/
/* randomize */

void seedWorld(unsigned char world1[8][8])
{
  int i, j;
  randomSeed(analogRead(analogPin));
  for (i = 0; i < SIZEX; i++)
  {
    for (j = 0; j < SIZEY; j++)
    {
      if (random(100) < density); {
        world1[i][j] = random(2);
      }
    }
  }
}

/*******************************************************************************/

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, brightness);
  lc.clearDisplay(0);
  seedWorld(world1);
}

/*******************************************************************************/

void loop()
{

  if (generation++ > reseedrate)
  {
    seedWorld(world1);
    lc.clearDisplay(0);
    delay(300);
    generation = 0;
  }

  previous_generation(world1, world2);
  neighbours(world1, world2);
  next_generation(world1, world2);
  display_cells(world1);
  delay(delaytime);


}
