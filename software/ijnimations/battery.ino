/*
	battery animation by Einstein
*/
int battery() {
  byte animation1[8] = {
    B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B01000010, B01111110
  };

  byte animation2[8] = {
    B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B01111110, B01111110
  };

  byte animation3[8] = {
    B00111100, B01000010, B01000010, B01000010, B01000010, B01111110, B01111110, B01111110
  };

  byte animation4[8] = {
    B00111100, B01000010, B01000010, B01000010, B01111110, B01111110, B01111110, B01111110
  };

  byte animation5[8] = {
    B00111100, B01000010, B01000010, B01111110, B01111110, B01111110, B01111110, B01111110
  };

  byte animation6[8] = {
    B00111100, B01000010, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110
  };

  byte animation7[8] = {
    B00111100, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110
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
