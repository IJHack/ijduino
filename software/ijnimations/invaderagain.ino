/*
	IJnimation invader again by realitygaps
*/
int invaderagain() {
	const byte invader1[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};

	const byte invader2[8]={
		B00000000,
		B00000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000};

	const byte invader3[8]={
		B00000000,
		B10000000,
		B11000000,
		B11000000,
		B01000000,
		B01000000,
		B01000000,
		B11000000};

	const byte invader4[8]={
		B10000000,
		B11000000,
		B01100000,
		B11100000,
		B10100000,
		B00100000,
		B00100000,
		B01100000};

	const byte invader5[8]={
		B01000000,
		B11100000,
		B10110000,
		B11110000,
		B01010000,
		B10010000,
		B00010000,
		B00110000};

	const byte invader6[8]={
		B00100000,
		B11110000,
		B11011000,
		B11111000,
		B00101000,
		B11001000,
		B00001000,
		B00011000};

	const byte invader7[8]={
		B10010000,
		B11111000,
		B01101100,
		B11111100,
		B10010100,
		B01100100,
		B00000100,
		B00001100};

	const byte invader8[8]={
		B01001000,
		B11111100,
		B10110110,
		B11111110,
		B01001010,
		B00110010,
		B00000010,
		B10000110};

	const byte invader9[8]={
		B00100100,
		B01111110,
		B11011011,
		B11111111,
		B10100101,
		B10011001,
		B10000001,
		B11000011};

	const byte invader9a[8]={
		B00100100,
		B00011000,
		B01111110,
		B11011011,
		B11111111,
		B11011011,
		B10011001,
		B11000011};

	const byte invader10[8]={
		B00010010,
		B00111111,
		B01101101,
		B01111111,
		B01010010,
		B01001100,
		B01000000,
		B01100001};


	const byte invader11[8]={
		B00001001,
		B00011111,
		B00110110,
		B00111111,
		B00101001,
		B00100110,
		B00100000,
		B00110000};



	const byte invader12[8]={
		B00000100,
		B00001111,
		B00011011,
		B00011111,
		B00010100,
		B00010011,
		B00010000,
		B00011000};

	const byte invader13[8]={
		B00000010,
		B00000111,
		B00001101,
		B00001111,
		B00001010,
		B00001001,
		B00001000,
		B00001100};


	const byte invader14[8]={
		B00000001,
		B00000011,
		B00000110,
		B00000111,
		B00000101,
		B00000100,
		B00000100,
		B00000110};

	const byte invader15[8]={
		B00000000,
		B00000001,
		B00000011,
		B00000011,
		B00000010,
		B00000010,
		B00000010,
		B00000011};

	const byte invader16[8]={
		B00000000,
		B00000000,
		B00000001,
		B00000001,
		B00000001,
		B00000001,
		B00000001,
		B00000001};

	bool skip;
	skip = render(invader1, 200);
	if (skip) {
		return true;
	}
	skip = render(invader2, 200);
	if (skip) {
		return true;
	}
	skip = render(invader3, 200);
	if (skip) {
		return true;
	}
	skip = render(invader4, 200);
	if (skip) {
		return true;
	}
	skip = render(invader5, 200);
	if (skip) {
		return true;
	}
	skip = render(invader6, 200);
	if (skip) {
		return true;
	}
	skip = render(invader7, 200);
	if (skip) {
		return true;
	}
	skip = render(invader8, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9a, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9a, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9a, 200);
	if (skip) {
		return true;
	}
	skip = render(invader9, 200);
	if (skip) {
		return true;
	}
	skip = render(invader10, 200);
	if (skip) {
		return true;
	}
	skip = render(invader11, 200);
	if (skip) {
		return true;
	}
	skip = render(invader12, 200);
	if (skip) {
		return true;
	}
	skip = render(invader13, 200);
	if (skip) {
		return true;
	}
	skip = render(invader14, 200);
	if (skip) {
		return true;
	}
	skip = render(invader15, 200);
	if (skip) {
		return true;
	}
	skip = render(invader16, 200);
	if (skip) {
		return true;
	}
	skip = render(invader1, 200);
	if (skip) {
		return true;
	}
	return false;
}

