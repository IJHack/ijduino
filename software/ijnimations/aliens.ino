/*
	IJnimation Aliens by Einstein
 */
const byte alien1[8] PROGMEM = {

  // Animation bitmaps. Each frame of animation MUST contain
  // 8 lines of graphics data (there is no error checking for
  // length). Each line should be prefixed with the letter 'B',
  // followed by exactly 8 binary digits (0 or 1), no more,
  // no less (again, no error checking). '0' represents an
  // 'off' pixel, '1' an 'on' pixel. End line with a comma.
  B00011000, // This is the first frame for alien #1
  B00111100, // If you squint you can kind of see the
  B01111110, // image in the 0's and 1's.
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101
    // The 9th line (required) is the time to display this frame,
  // in 1/100ths of a second (e.g. 100 = 1 sec, 25 = 1/4 sec,
  // etc.). Range is 0 (no delay) to 255 (2.55 seconds). If
  // longer delays are needed, make duplicate frames.
  //25, // 0.25 seconds
};

const byte alien2[8] PROGMEM = {
  B00011000, // This is the second frame for alien #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
    //25, // 0.25 second delay
};

const byte alien3[8] PROGMEM = {
  // Frames 3 & 4 for alien #1 are duplicates of frames 1 & 2.
  // Rather than list them 'the tall way' again, the lines are merged here...
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101
};

const byte alien4[8] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

const byte alien5[8] PROGMEM = {

  B00000000, // First frame for alien #2
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B11000011
    //25, // 0.25 second delay
};

const byte alien6[8] PROGMEM = {
  B00111100, // Second frame for alien #2
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B00100100,
  B00100100
    //25,
};

const byte alien7[8] PROGMEM = {
  // Frames 3 & 4 for alien #2 are duplicates of frames 1 & 2
  B00000000,
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B11000011
};

const byte alien8[8] PROGMEM = {
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B00100100,
  B00100100
};

const byte alien9[8] PROGMEM = {

  B00100100, // First frame for alien #3
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
    //25,
};

const byte alien10[8] PROGMEM = {
  B00100100, // Second frame for alien #3
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
    //25,
};

const byte alien11[8] PROGMEM = {
  // Frames are duplicated as with prior aliens
  B00100100,
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

const byte alien12[8] PROGMEM = {
  B00100100,
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

const byte alien13[8] PROGMEM = {
  B00111100, // First frame for alien #4
  B01111110,
  B10110011,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00000000
    //12, // ~1/8 second delay
};

const byte alien14[8] PROGMEM = {
  B00111100, // Second frame for alien #4
  B01111110,
  B10011001,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00001000
    //12,
};

const byte alien15[8] PROGMEM = {
  B00111100, // Third frame for alien #4 (NOT a repeat of frame 1)
  B01111110,
  B11001101,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00001000
    //12,
};

const byte alien16[8] PROGMEM = {
  B00111100, // Fourth frame for alien #4 (NOT a repeat of frame 2)
  B01111110,
  B11100111,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00000000
    //12,
};

const byte alien17[8] PROGMEM = {
  // Frames 5-8 are duplicates of 1-4, lines merged for brevity
  B00111100,
  B01111110,
  B10110011,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00000000
};

const byte alien18[8] PROGMEM = {
  B00111100,
  B01111110,
  B10011001,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00001000
};

const byte alien19[8] PROGMEM = {
  B00111100,
  B01111110,
  B11001101,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00001000
};

const byte alien20[8] PROGMEM = {
  B00111100,
  B01111110,
  B11100111,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00000000
};

int aliens() {


  bool skip;
  skip = render(alien1, 200);
  if (skip) {
    return true;
  }
  skip = render(alien2, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien3, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien4, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien5, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien6, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien7, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien8, 200);
  if (skip) {
    return true;
  } 
  skip = render(alien9, 200);
  if (skip) {
    return true;
  }
  skip = render(alien10, 200);
  if (skip) {
    return true;
  }
  skip = render(alien11, 200);
  if (skip) {
    return true;
  }
  skip = render(alien12, 200);
  if (skip) {
    return true;
  }
  skip = render(alien13, 200);
  if (skip) {
    return true;
  }
  skip = render(alien14, 200);
  if (skip) {
    return true;
  }
  skip = render(alien15, 200);
  if (skip) {
    return true;
  }
  skip = render(alien16, 200);
  if (skip) {
    return true;
  }
  skip = render(alien17, 200);
  if (skip) {
    return true;
  }
  skip = render(alien18, 200);
  if (skip) {
    return true;
  }
  skip = render(alien19, 200);
  if (skip) {
    return true;
  }
  skip = render(alien20, 200);
  if (skip) {
    return true;
  }
  return false;
}

