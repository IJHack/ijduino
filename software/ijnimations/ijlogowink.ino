/*
	IJnimation IJwink by realitygaps, Einstein, the_JinX, damnlie
 */
const byte logowink0[8] PROGMEM = {
  B11000011,
  B11000011,
  B00000000,
  B00000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100};

const byte logowink1[8] PROGMEM = {  
  B00000011,
  B00000011,
  B00000000,
  B00000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100};

const byte logowink2[8] PROGMEM = {  
  B11000000,
  B11000000,
  B00000000,
  B00000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100};

const byte logowink3[8] PROGMEM = {  
  B11000011,
  B11000011,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000};

int ijlogowink() {
  bool skip;
  skip = render(logowink0, 500);
  if (skip) {
    return true;
  }
  skip = render(logowink1, 500);
  if (skip) {
    return true;
  }
  skip = render(logowink0, 500);
  if (skip) {
    return true;
  }  
  skip = render(logowink2, 500);
  if (skip) {
    return true;
  }
  skip = render(logowink0, 500);
  if (skip) {
    return true;
  }
  skip = render(logowink3, 500);  
  if (skip) {
    return true;
  }
  return false;
}

