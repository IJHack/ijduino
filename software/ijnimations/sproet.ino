/*
	IJnimation bij Sproet
 */
const byte sproet1[8] PROGMEM = {B10010010,
B01101101,
B10010010,
B01101101,
B10010010,
B01101101,
B10010010,
B01101101};

const byte sproet2[8] PROGMEM = {B01001001,
B10110110,
B01001001,
B10110110,
B01001001,
B10110110,
B01001001,
B10100110};

const byte sproet3[8] PROGMEM = {B01101101,
B10010010,
B01101101,
B10010010,
B01101101,
B10010010,
B01101101,
B10010010};

const byte sproet4[8] PROGMEM = {B00101001,
B10010010,
B01100101,
B10010010,
B01001001,
B10010010,
B00101101,
B10010010};

const byte sproet5[8] PROGMEM = {B00101000,
B10010010,
B00100101,
B10010000,
B01001000,
B00010010,
B00100001,
B10010010};

const byte sproet6[8] PROGMEM = {B00101000,
B10000000,
B00100101,
B00000000,
B01001000,
B00000010,
B00000000,
B10010010};

const byte sproet7[8] PROGMEM = {B00000000,
B00000000,
B00101000,
B00010100,
B01001000,
B00010010,
B00000000,
B00010000};

const byte sproet8[8] PROGMEM = {B00000000,
B00000000,
B00101000,
B00010100,
B01001000,
B00010010,
B00000000,
B00010000};

const byte sproet9[8] PROGMEM = {B00000000,
B00000000,
B00100000,
B00000100,
B00000000,
B00010000,
B00000000,
B00000000};

const byte sproet10[8] PROGMEM = {B00000000,
B00000000,
B00000000,
B00010000,
B00001000,
B00000000,
B00000000,
B00000000};

const byte sproet11[8] PROGMEM = {B10000100,
B00000010,
B00000000,
B00000000,
B00000000,
B10000000,
B00000000,
B00010001};

const byte sproet12[8] PROGMEM = {B10000100,
B01001010,
B00110000,
B00010000,
B01001000,
B10010100,
B00010010,
B00010001};

const byte sproet13[8] PROGMEM = {B10000100,
B01001010,
B00111000,
B00111110,
B01111000,
B10111100,
B00010010,
B00010001};

const byte sproet14[8] PROGMEM = {B10000100,
B01001010,
B00110000,
B00101110,
B01010000,
B10111100,
B00010010,
B00010001};

const byte sproet15[8] PROGMEM = {B00101010,
B10001001,
B00110000,
B10101111,
B01010000,
B10111101,
B00010010,
B10010101};

const byte sproet16[8] PROGMEM = {B00101010,
B11001001,
B00110100,
B10100111,
B01010100,
B10100101,
B01011010,
B10110101};

const byte sproet17[8] PROGMEM = {B00101010,
B11111111,
B00110100,
B10100111,
B01110100,
B10100101,
B11111111,
B10110101};

const byte sproet18[8] PROGMEM = {B00101010,
B11111111,
B00100100,
B10110111,
B10101100,
B00100101,
B11111111,
B00110100};

const byte sproet19[8] PROGMEM = {B00100100,
B11111111,
B00100100,
B00100100,
B00100100,
B00100100,
B11111111,
B00100100};

const byte sproet20[8] PROGMEM = {B01000010,
B11111111,
B01000010,
B01000010,
B01000010,
B01000010,
B11111111,
B01000010};

const byte sproet21[8] PROGMEM = {B11111111,
B01000010,
B01000010,
B01000010,
B01000010,
B01000010,
B01000010,
B11111111};

const byte sproet22[8] PROGMEM = {B11111111,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B11111111};

const byte sproet23[8] PROGMEM = {B11111111,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B11111111};

const byte sproet24[8] PROGMEM = {B10101010,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B10101010};

const byte sproet25[8] PROGMEM = {B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};

const byte sproet26[8] PROGMEM = {B00000000,
B00000000,
B00000000,
B00001000,
B00010000,
B00000000,
B00000000,
B00000000};

const byte sproet27[8] PROGMEM = {B00000000,
B00000000,
B00100000,
B00001000,
B00010000,
B00000100,
B00000000,
B00000000};

const byte sproet28[8] PROGMEM = {B10000000,
B01000000,
B00100000,
B00001000,
B00010000,
B00000100,
B00000010,
B00000001};

const byte sproet29[8] PROGMEM = {B10000011,
B01000100,
B00100100,
B00001000,
B00010000,
B00100100,
B00100010,
B11000001};

const byte sproet30[8] PROGMEM = {B01000000,
B00100010,
B00010101,
B00001000,
B00010000,
B10101000,
B01000100,
B00000010};

const byte sproet31[8] PROGMEM = {B00100000,
B00010000,
B00001100,
B10001010,
B01010001,
B00110000,
B00001000,
B00000100};




int sproet() {
  bool skip = render(sproet1, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet2, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet3, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet4, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet5, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet6, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet7, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet8, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet9, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet10, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet11, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet12, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet13, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet14, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet15, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet16, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet17, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet18, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet19, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet20, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet21, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet22, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet23, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet24, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet25, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet26, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet27, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet28, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet29, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet30, 500);
  if (skip) {
    return true;
  }
  skip = render(sproet31, 500);
  if (skip) {
    return true;
  }
  return false;
}

