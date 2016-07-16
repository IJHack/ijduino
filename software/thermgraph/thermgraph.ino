// Graphic thermometer: shows to indicate if temperature
// goes up of down. It uses DHT22, but probably also
// works with DHT11.

#include "LedControl.h"     //Imports the library

static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

#define brightness 1       //Values from 1 to 15 to set the brightness

#define DHTPIN A3          // A3 is pin 26 (PC3/ADC3/PCINT11) of atmega328
#define TIMEOUT 10000

#define SHIFT_EVERY_MIN   5
#define SHIFT_AT_STEPS   (24*SHIFT_EVERY_MIN)

uint16_t shiftstep;
uint8_t last_temp;
uint16_t base_temp;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, brightness);
  lc.clearDisplay(0);
  Serial.begin(9600);
  Serial.println("Start");
  shiftstep = 0;
  base_temp = 0;
}

uint8_t matrix[8];

void loop() {
  uint8_t data[5] = { 0, 0, 0, 0, 0 };
  
  uint8_t mask = 128;
  uint8_t idx = 0;

  uint8_t bit = digitalPinToBitMask(DHTPIN);
  uint8_t port = digitalPinToPort(DHTPIN);
  volatile uint8_t *PIR = portInputRegister(port);

  // REQUEST SAMPLE
  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, HIGH); // T-be 
  delay(250);
  // switch last value on
  if (base_temp != 0)
  {
    matrix[last_temp] |= 1;
    lc.setColumn(0, last_temp, matrix[last_temp]);
  }      
  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, LOW);   // T-go
  delay(20);
  digitalWrite(DHTPIN, HIGH);
  delayMicroseconds(40);
  pinMode(DHTPIN, INPUT_PULLUP);
  delayMicroseconds(10);
  
  uint32_t t_mid = micros();

  // GET ACKNOWLEDGE or TIMEOUT
  uint16_t loopCntLOW = TIMEOUT;
  while ((*PIR & bit) == LOW )  // T-rel
  {
    if (--loopCntLOW == 0)
    {
      //Serial.println("Low init err");
      return;
    }
  }

  t_mid = 50; //(10 + micros() - t_mid)*50/80;

  uint16_t loopCntHIGH = TIMEOUT;
  while ((*PIR & bit) != LOW )  // T-reh
  {
    if (--loopCntHIGH == 0)
    {
      //Serial.println("Error 2");
      return;
    }
  }

  for (uint8_t i = 0; i < 40; i++)
  {
    loopCntLOW = TIMEOUT;
    while ((*PIR & bit) == LOW )
    {
      if (--loopCntLOW == 0)
      {
        //Serial.print("Error 3, cycle "); Serial.print(i);
        return;
      }
    }

    uint32_t t = micros();

    loopCntHIGH = TIMEOUT;
    while ((*PIR & bit) != LOW )
    {
      if (--loopCntLOW == 0)
      {
        //Serial.print("Error 4, cycle "); Serial.print(i);
        return;
      }
    }

    data[i/8] <<= 1;
    if (micros() - t > t_mid)
      data[i/8] |= 1;
  }
  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, HIGH);

/*
  for (uint8_t i = 0; i < 40; i++)
  {
    if (i % 8 == 0)
      Serial.println();
    Serial.print(cycles[i]);
    
    if (data[i/8] & (1 << (7-i%8)))
      Serial.print("_ ");
    else
      Serial.print("X ");
  }
  */
  for (uint8_t i = 0; i < 5; i++)
  {
     Serial.print(data[i]);
     Serial.print(" ");
  }
  Serial.println();
  if (data[4] != ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
    Serial.println("Checksum err");
    return;
  }
  uint16_t temp = ((uint16_t)data[2])*256 + data[3];
  Serial.print("Temp = ");
  Serial.print(temp);
  Serial.println();

  temp /= 2;

  if (base_temp == 0)
  {
    base_temp = temp - 3;
  }
  bool did_move = false;

  // move up or down depending on new measurement
  while (temp < base_temp)
  {
    for (uint8_t i = 7; i > 0; i--)
      matrix[i] = matrix[i-1];
    matrix[0] = 0;
    base_temp--;
    did_move = true;
  }
  while (temp > base_temp + 7)
  {
    for (uint8_t i = 0; i < 7; i++)
      matrix[i] = matrix[i+1];
    matrix[7] = 0;
    base_temp++;
    did_move = true;
  }
  last_temp = temp - base_temp;

  // move left after number of steps, only if did not move up or down
  if (++shiftstep >= SHIFT_AT_STEPS && !did_move)
  {
    for (uint8_t i = 0; i < 8; i++)
      matrix[i] <<= 1;
    shiftstep -= SHIFT_AT_STEPS;
    did_move = true;
  }

  matrix[last_temp] |= 1;

  // if did not move, move up or down to center graph
  if (!did_move)
  {
  	uint8_t top = 0; // empty lines on the top
    for (; top < 7; top++)
      if (matrix[7-top] != 0)
        break;
  	uint8_t bottom = 0; // empty lines on the bottom
    for (; bottom < 7; bottom++)
      if (matrix[bottom] != 0)
        break;
    if (bottom >= top + 2)
    {
	    for (uint8_t i = 0; i < 7; i++)
	      matrix[i] = matrix[i+1];
	    matrix[7] = 0;
	    base_temp++;
      last_temp--;
    }
    if (top >= bottom + 2)
    {
      for (uint8_t i = 7; i > 0; i--)
        matrix[i] = matrix[i-1];
      matrix[0] = 0;
      base_temp--;
      last_temp++;
    }
  }

  // update display
  for (uint8_t i = 0; i < 8; i++)
    lc.setColumn(0, i, matrix[i]);

  // blink last temperature for 2 seconds 
  for (uint8_t s = 0;;)
  {
    delay(200);
    matrix[last_temp] &= 254;
    lc.setColumn(0, last_temp, matrix[last_temp]);
    if (s++ == 5)
      break;
    delay(200);
    matrix[last_temp] |= 1;
    lc.setColumn(0, last_temp, matrix[last_temp]);
  }
}
