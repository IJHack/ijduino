/*
	IJnimation invadesuid by realitygaps
 */
const byte invadesquid1[8] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B01011010,
  B10000001,
  B01000010};

const byte devadesquid1[8] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101};

int invadesquid() {
  bool skip = render(invadesquid1, 500);
  if (skip) {
    return true;
  }
  skip = render(devadesquid1, 500);  
  if (skip) {
    return true;
  }
  return false;
}


