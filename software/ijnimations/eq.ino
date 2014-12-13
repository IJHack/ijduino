/*
	IJnimation EQ by realitygaps
 */
const byte eq1[8] PROGMEM = {
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11111100,
  B11111100,
  B11111111,
  B11111111};

const byte eq2[8] PROGMEM = {
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11111100,
  B11111100,
  B11111111,
  B11111111};

const byte eq3[8] PROGMEM = {
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11111100,
  B11111100,
  B11111111,
  B11111111};

const byte eq4[8] PROGMEM = {
  B00000000,
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11111111,
  B11111111,
  B11111111};

const byte eq5[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00001100,
  B11001111,
  B11001111,
  B11111111,
  B11111111};

const byte eq6[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00001111,
  B11001111,
  B11001111,
  B11111111};

const byte eq7[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00001111,
  B00001111,
  B11001111,
  B11001111};

const byte eq8[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00001111,
  B00001111,
  B11111111};

const byte eq9[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00111111,
  B11111111};

const byte eq10[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00111111,
  B11111111};

const byte eq11[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00001111,
  B11001111,
  B11111111};

const byte eq12[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001100,
  B11001111,
  B11111111,
  B11111111};

const byte eq13[8] PROGMEM = {
  B00000000,
  B00000000,
  B00000000,
  B00001100,
  B11001100,
  B11111111,
  B11111111,
  B11111111};

const byte eq14[8] PROGMEM = {
  B00000000,
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11111111,
  B11111111,
  B11111111};

const byte eq15[8] PROGMEM = {
  B00000000,
  B00001100,
  B11001100,
  B11001100,
  B11001100,
  B11111100,
  B11111111,
  B11111111};

int eq() {
  bool skip;
  skip = render(eq1, 50);
  if (skip) {
    return true;
  }
  skip = render(eq2, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq3, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq4, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq5, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq6, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq7, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq8, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq9, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq10, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq11, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq12, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq13, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq14, 50);  
  if (skip) {
    return true;
  }
  skip = render(eq15, 50);     
  if (skip) {
    return true;
  }
  return false;
}


