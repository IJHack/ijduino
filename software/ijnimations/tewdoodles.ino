/*
	Impressive 9 frame animation that will simply blow your mind!
 
 	http://i.imgur.com/O55vc.gif
 
 	By tew
 */
const byte tewdoodle1[8] PROGMEM =
{
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};

const byte tewdoodle2[8] PROGMEM ={
  B10000001,
  B01111110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B10000001  };

const byte tewdoodle3[8] PROGMEM ={
  B10000001,
  B01000010,
  B00111100,
  B00100100,
  B00100100,
  B00111100,
  B01000010,
  B10000001  };

const byte tewdoodle4[8] PROGMEM ={
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001  };

const byte tewdoodle5[8] PROGMEM ={
  B00000000,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B00000000  };

const byte tewdoodle6[8] PROGMEM ={
  B00000000,
  B00000000,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B00000000,
  B00000000  };

const byte tewdoodle7[8] PROGMEM ={
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000  };

const byte tewdoodle8[8] PROGMEM ={
  B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00001000,
  B00000000,
  B00000000,
  B00000000  };

const byte tewdoodle9[8] PROGMEM ={
  B00000000,
  B00000000,
  B00000000,
  B00001000,
  B00010000,
  B00000000,
  B00000000,
  B00000000  };

int tewdoodles() {

  bool skip;
  skip = render(tewdoodle1, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle2, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle3, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle4, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle5, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle6, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle7, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle8, 100);
  if (skip) {
    return true;
  }
  skip = render(tewdoodle9, 100);
  if (skip) {
    return true;
  }
  return false;

}

