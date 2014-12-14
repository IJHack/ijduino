/*
	battery animation by Einstein
 */

const byte animation1[8] PROGMEM = {
  B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B01000010, B01111110
};

const byte animation2[8] PROGMEM = {
  B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B01111110, B01111110
};

const byte animation3[8] PROGMEM = {
  B00111100, B01000010, B01000010, B01000010, B01000010, B01111110, B01111110, B01111110
};

const byte animation4[8] PROGMEM = {
  B00111100, B01000010, B01000010, B01000010, B01111110, B01111110, B01111110, B01111110
};

const byte animation5[8] PROGMEM = {
  B00111100, B01000010, B01000010, B01111110, B01111110, B01111110, B01111110, B01111110
};

const byte animation6[8] PROGMEM = {
  B00111100, B01000010, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110
};

const byte animation7[8] PROGMEM = {
  B00111100, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110
};

int battery() {
  bool skip = render(animation1, 500);
  if (skip) {
    return true;
  }
  skip = render(animation2, 500);
  if (skip) {
    return true;
  }
  skip = render(animation3, 500);
  if (skip) {
    return true;
  }
  skip = render(animation4, 500);
  if (skip) {
    return true;
  }
  skip = render(animation5, 500);
  if (skip) {
    return true;
  }
  skip = render(animation6, 500);
  if (skip) {
    return true;
  }
  skip = render(animation7, 500);
  if (skip) {
    return true;
  }
  return false;
}

