/*
	IJnimation 'diagonals' by Yvette Cendes
 */
const byte diagonal1[8] PROGMEM = {
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010
};

const byte diagonal2[8] PROGMEM = {
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101
};

int diagonals() {
  bool skip = render(diagonal1, 500);
  if (skip) {
    return true;
  }
  skip = render(diagonal2, 500);
  if (skip) {
    return true;
  }
  return false;
}

