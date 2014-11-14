/*
	xmastree by Einstein
*/int xmastree() {
  byte animation1[8] = {
B10011000,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
};

  byte animation2[8] = {
B00011001,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
  };

  byte animation3[8] = {
B01011000,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
  };


  byte animation4[8] = {
B00011010,B00111100,B01111110,B11111111,B00111100,B01111110,B11111111,B00011000
  };


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
  return false;
}
