/*
	IJnimation heartbeatbeat by realitygaps
 */
const byte heartbeat1[8] PROGMEM = {
  B00000000,
  B00000100,
  B00000110,
  B00000101,
  B11100100,
  B00010100,
  B00001100,
  B00000100};

const byte heartbeat2[8] PROGMEM = {
  B00000000,
  B00000010,
  B00000011,
  B00000010,
  B11110010,
  B00001010,
  B00000110,
  B00000010};

const byte heartbeat3[8] PROGMEM = {
  B00000000,
  B00000001,
  B00000001,
  B00000001,
  B11111001,
  B00000101,
  B00000011,
  B00000001};

const byte heartbeat4[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111100,
  B00000010,
  B00000001,
  B00000000};

const byte heartbeat5[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111110,
  B00000001,
  B00000000,
  B00000000};

const byte heartbeat6[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B00000000,
  B00000000,
  B00000000};

const byte heartbeat7[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B01111111,
  B00000000,
  B00000000,
  B00000000};

const byte heartbeat8[8] PROGMEM = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B00111111,
  B00000000,
  B00000000,
  B00000000};

const byte heartbeat9[8] PROGMEM = {
  B00000000,
  B10000000,
  B11000000,
  B10100000,
  B10011111,
  B10000000,
  B10000000,
  B10000000};

const byte heartbeat10[8] PROGMEM = {
  B00000000,
  B01000000,
  B01100000,
  B01010000,
  B01001111,
  B01000000,
  B11000000,
  B01000000};

const byte heartbeat11[8] PROGMEM = {
  B00000000,
  B00100000,
  B00110000,
  B00101000,
  B00100111,
  B10100000,
  B01100000,
  B00100000};

const byte heartbeat12[8] PROGMEM = {
  B00000000,
  B00010000,
  B00011000,
  B00010100,
  B10010011,
  B01010000,
  B00110000,
  B00010000};

const byte heartbeat13[8] PROGMEM = {
  B00000000,
  B00001000,
  B00001100,
  B00001010,
  B11001001,
  B00101000,
  B00011000,
  B00001000};

int heartbeat() {
  bool skip;
  skip = render(heartbeat6, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat6, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat7, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat8, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat9, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat10, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat11, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat12, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat13, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat1, 100);
  if (skip) {
    return true;
  }
  skip = render(heartbeat2, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat3, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat4, 100);  
  if (skip) {
    return true;
  }
  skip = render(heartbeat5, 100);
  if (skip) {
    return true;
  }
  skip = render(heartbeat6, 100);  
  if (skip) {
    return true;
  }
  return false;
}


