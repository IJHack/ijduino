/*                           TETRIJS
 * Not finished !!
 * Based on code from 
 * http://open-source-project.com/projects/arduino-led-tetris/tetris-source-code/
 */
 
#include <LedControl.h>

LedControl lc = LedControl(20, 5, 21, 1);

const unsigned short brick_count = 7;
const unsigned int bricks[ brick_count ][4] = {
  { //1×4
    0b0100010001000100,
    0b0000000011110000,
    0b0100010001000100,
    0b0000000011110000
  },
  { // T
    0b0100111000000000,
    0b0100011001000000,
    0b1110010000000000,
    0b0100110001000000
  },
  { //2×2
    0b0000011001100000,
    0b0000011001100000,
    0b0000011001100000,
    0b0000011001100000
  },
  { // L
    0b0000000011100010,
    0b0000010001001100,
    0b0000100011100000,
    0b0000011001000100
  },
  { //Reverse L
    0b0000000011101000,
    0b0000110001000100,
    0b0000001011100000,
    0b0000010001000110
  },
  { // Z
    0b0000100011000100,
    0b0000011011000000,
    0b0000100011000100,
    0b0000011011000000
  },
  { // S
    0b0000010011001000,
    0b0000110001100000,
    0b0000010011001000,
    0b0000110001100000
  }
};

int rightButton = 40;
int leftButton = 42;
int upButton = 44;
int downButton = 46;

boolean lastrButton = digitalRead(rightButton);
boolean lastlButton = digitalRead(leftButton);
boolean lastdButton = digitalRead(downButton);
boolean lastuButton = digitalRead(upButton);

int timer = 0;
int timeOut = 100;

boolean ground = false;
boolean wall[8][8];
boolean current_brick[4][4];
boolean sides = false;
boolean drop = false;
boolean leftBrick = false;
boolean rightBrick = false;
boolean rotate = false;

int current_brick_type = 0;//0;
int next_brick_type = 0;
int rotation = 0;//0;
int pos_x = 2;
int pos_y = 0;
int lastKey = 0;

void setup() {

  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  Serial.begin(9600);

  clearWall();
  updateBrickArray();
}

void loop() {

  lastKey = input();

  if ( lastKey == 1) { // Shift left
    leftBrick == checkLeftBrick();
    if ( leftBrick == false ) {
      pos_x--;
      checkSides();
      lastlButton = HIGH;
    }
  }

  if ( lastKey == 2 ) { // Shift right
    rightBrick = checkRightBrick();
    if ( rightBrick == false ) {
      pos_x++;
      checkSides();
      lastrButton = HIGH;
    }
  }

  if ( lastKey == 3 ) { // Rotation
    if ( checkRotate() == false ) {
      rotation++;
      if ( rotation >= 4 ) {
        rotation = 0;
      }
    }
    updateBrickArray();
    lastuButton = HIGH;
  }

  if ( lastKey == 4 ) { // Drop block
    timer = timeOut;
    delay(50);
  }
  checkSides();
  disp();
  tick();
  delay(10);
}

int input() {

  if ( digitalRead( leftButton ) == HIGH && lastlButton == LOW ) { //check left key
    return 1;
  }
  else {
    lastlButton = digitalRead( leftButton );
  }

  if ( digitalRead( rightButton ) == HIGH && lastrButton == LOW ) { //check right key
    return 2;
  }
  else {
    lastrButton = digitalRead( rightButton );
  }

  if ( digitalRead( upButton ) == HIGH && lastuButton == LOW ) {
    return 3;
  }
  else {
    lastuButton = digitalRead( upButton );
  }

  if ( digitalRead( downButton ) == HIGH && lastdButton == LOW ) {
    return 4;
  }
  else {
    lastdButton = digitalRead( downButton );
  }
  return 0;
}
void updateBrickArray()
{
  int data = bricks[current_brick_type][rotation];
  for ( int i = 0; i < 4; i++ )
  {
    for ( int k = 0; k < 4; k++ )
    {
      current_brick[k][i] = bitRead(data, 4 * i + 3 - k);
    }
  }
}
void disp() {

  lc.clearDisplay(0);
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      if (current_brick[x][y] == true) {
        lc.setLed(0, x + pos_x , y + pos_y , true);
      }
    }
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {

      if (wall[x][y] == true) {
        lc.setLed(0, x, y, true);
      }
    }
  }
}
void checkSides() {

  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k;

        if ( x >= 8 || wall[x][y] >= 8 ) { // check if brick is in the right wall
          pos_x--; // shift left if true
        }
        if ( x <= -1 || wall[x][y] <= -1 ) { // check if brick is in the left wall
          pos_x++; // shift right if true
        }
      }
    }
  }
}
boolean checkLeftBrick() {

  leftBrick = false;

  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k;

        if ( wall[x - 1][y] == true ) {
          leftBrick = true;
          Serial.println("Left Brick!");
        }
      }
    }
  }
  return leftBrick;
}

boolean checkRightBrick() {

  rightBrick = false;

  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k;

        if ( wall[x + 1][y] == true ) {
          rightBrick = true;
          Serial.println("Right Brick!");
        }
      }
    }
  }
  return rightBrick;
}
boolean checkDrop() {

  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k + 1;

        if ( y >= 8 ) {
          return true;
        }

        if ( wall[x][y] == true ) {
          return true;
        }
      }
    }
  }
  return false;
}

void tick() {

  drop = checkDrop();
  if ( timer == timeOut ) {
    if ( drop == true ) {
      addToWall();
      current_brick_type++;
      if ( current_brick_type >= 7 ) {
        current_brick_type = 0;
      }
      checkLine();
      updateBrickArray();
      pos_y = 0;
      pos_x = 2;
      timer = 0;
    }
    else if ( drop == false ) {
      pos_y++;
      timer = 0;
    }
  }
  timer++;
}

void addToWall() {

  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k;

        wall[x][y] = true;
      }
    }
  }
}

void clearWall() {
  for ( int i = 0; i < 8; i++ ) {
    for ( int k = 0; k < 8; k++ ) {
      wall[i][k] = false;
    }
  }
}

boolean checkRotate() {

  rotation++;
  updateBrickArray();
  for ( int i = 0; i < 4; i++ ) {
    for ( int k = 0; k < 4; k++ ) {
      if ( current_brick[i][k] == true ) {

        int x = pos_x + i;
        int y = pos_y + k;

        if ( wall[x][y] == true ) {
          Serial.println("Rotation blockage!");
          rotation--;
          return true;
        }
      }
    }
  }
  rotation--;
  return false;
}
void moveRowDown(int row)
{
  //move "row" down one
  for (int c = 0; c < 8; c++)
  {
    wall[c][row + 1] = wall[c][row];
    wall[c][row] = false;
  }
}
void rowCleared(int row)
{
  int rowAbove = row - 1;

  for (int r = rowAbove; r >= 0; r--)
  {
    moveRowDown(r);
  }
}
void checkLine() {

  int line = 0;
  for ( int i = 0; i <= 7; i++ ) {
    line = 0;
    for ( int k = 0; k <= 7; k++ ) {
      if ( wall[k][i] == true ) {
        line++;
      }
      if ( line == 8 ) {

        for ( int k = 0; k < 8; k++ ) {
          wall[k][i] = false;
          Serial.println("Line!");
        }
        rowCleared(i);
      }
    }
  }

}

