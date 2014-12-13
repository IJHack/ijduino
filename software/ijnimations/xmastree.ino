/*
	xmastree by Einstein
 */
const byte xmastree1[8] PROGMEM = {
  B10011000,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
};

const byte xmastree2[8] PROGMEM = {
  B00011001,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
};

const byte xmastree3[8] PROGMEM = {
  B01011000,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
};


const byte xmastree4[8] PROGMEM = {
  B00011010,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
};

int xmastree() {
  bool skip = render(xmastree1, 500);
  if (skip) {
    return true;
  }
  skip = render(xmastree2, 500);
  if (skip) {
    return true;
  } 
  skip = render(xmastree3, 500);
  if (skip) {
    return true;
  }
  skip = render(xmastree4, 500);
  if (skip) {
    return true;
  }
  return false;
}

