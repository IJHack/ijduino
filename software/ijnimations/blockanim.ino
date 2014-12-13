/*
	IJnimation blockanim by Einstein
 */
const byte ba1[8] PROGMEM = {
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};

const byte ba2[8] PROGMEM = {
  B00000000,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00000000
};

const byte ba3[8] PROGMEM = {
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00000000,
  B00000000
};

const byte ba4[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};

const byte ba5[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

const byte ba6[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};

const byte ba7[8] PROGMEM = {
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00000000,
  B00000000
};

const byte ba8[8] PROGMEM = {

  B00000000,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00000000
};

const byte ba9[8] PROGMEM = {

  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};

const byte ba10[8] PROGMEM = {

  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111

};
int blockanim() {
  bool skip;
  skip = render(ba1, 200);
  if (skip) {
    return true;
  }
  skip = render(ba2, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba3, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba4, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba5, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba6, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba7, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba8, 200);
  if (skip) {
    return true;
  } 
  skip = render(ba9, 200);
  if (skip) {
    return true;
  }
  skip = render(ba10, 200);
  if (skip) {
    return true;
  }
  return false;
}

