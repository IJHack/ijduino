/*
	IJnimation pulse by Einstein
 */
const byte bigHeart[] PROGMEM = {
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000};

const byte smallHeart[] PROGMEM = {
  B00000000,
  B00000000,
  B00010100,
  B00111110,
  B00111110,
  B00011100,
  B00001000,
  B00000000};
  
int pulse() {
  bool skip = render(bigHeart, 500);
  if (skip) {
    return true;
  }
  skip = render(smallHeart, 500);
  if (skip) {
    return true;
  }
  return false;
}

