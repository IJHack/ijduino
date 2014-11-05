/*
	IJnimation pong byrealitygaps
*/
int pong() {
	byte pong1[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00011100};

	byte pong2[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000001,
		B00000000,
		B00001110};

	byte pong3[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000010,
		B00000111};


	byte pong4[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000100,
		B00000000,
		B00000111};

	byte pong5[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00001000,
		B00000000,
		B00000000,
		B00000111};

	byte pong6[8]={
		B00111000,
		B00000000,
		B00000000,
		B00010000,
		B00000000,
		B00000000,
		B00000000,
		B00001110};

	byte pong7[8]={
		B01110000,
		B00000000,
		B00100000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00001110};

	byte pong8[8]={
		B11100000,
		B01000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00011100};

	byte pong9[8]={
		B11100000,
		B00000000,
		B00100000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00011100};

	byte pong10[8]={
		B11100000,
		B00000000,
		B00000000,
		B00010000,
		B00000000,
		B00000000,
		B00000000,
		B00111000};

	byte pong11[8]={
		B01110000,
		B00000000,
		B00000000,
		B00000000,
		B00001000,
		B00000000,
		B00000000,
		B01110000};

	byte pong12[8]={
		B01110000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000100,
		B00000000,
		B00111000};

	byte pong13[8]={
		B01110000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000010,
		B00011100};

	byte pong14[8]={
		B00111000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00011101};

	bool skip;
	skip = render(pong1, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong2, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong3, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong4, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong5, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong6, 200);
	if (skip) {
		return true;
	}
	skip = render(pong7, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong8, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong9, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong10, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong11, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong12, 200);
	if (skip) {
		return true;
	}
	skip = render(pong13, 200);  
	if (skip) {
		return true;
	}
	skip = render(pong14, 200);  
	if (skip) {
		return true;
	}
	return false;
}

