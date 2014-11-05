/*
	IJnimation heartbeat by realitygaps
*/
int heartbeat() {
	byte heart1[8]={
		B00000000,
		B00000100,
		B00000110,
		B00000101,
		B11100100,
		B00010100,
		B00001100,
		B00000100};

	byte heart2[8]={
		B00000000,
		B00000010,
		B00000011,
		B00000010,
		B11110010,
		B00001010,
		B00000110,
		B00000010};

	byte heart3[8]={
		B00000000,
		B00000001,
		B00000001,
		B00000001,
		B11111001,
		B00000101,
		B00000011,
		B00000001};

	byte heart4[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111100,
		B00000010,
		B00000001,
		B00000000};

	byte heart5[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111110,
		B00000001,
		B00000000,
		B00000000};

	byte heart6[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111111,
		B00000000,
		B00000000,
		B00000000};

	byte heart7[8]={
		B00000000,
		B00000000,
		B00000000,
		B10000000,
		B01111111,
		B00000000,
		B00000000,
		B00000000};

	byte heart8[8]={
		B00000000,
		B00000000,
		B10000000,
		B01000000,
		B00111111,
		B00000000,
		B00000000,
		B00000000};

	byte heart9[8]={
		B00000000,
		B10000000,
		B11000000,
		B10100000,
		B10011111,
		B10000000,
		B10000000,
		B10000000};

	byte heart10[8]={
		B00000000,
		B01000000,
		B01100000,
		B01010000,
		B01001111,
		B01000000,
		B11000000,
		B01000000};

	byte heart11[8]={
		B00000000,
		B00100000,
		B00110000,
		B00101000,
		B00100111,
		B10100000,
		B01100000,
		B00100000};

	byte heart12[8]={
		B00000000,
		B00010000,
		B00011000,
		B00010100,
		B10010011,
		B01010000,
		B00110000,
		B00010000};

	byte heart13[8]={
		B00000000,
		B00001000,
		B00001100,
		B00001010,
		B11001001,
		B00101000,
		B00011000,
		B00001000};

	bool skip;
	skip = render(heart6, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart6, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart7, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart8, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart9, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart10, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart11, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart12, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart13, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart1, 100);
	if (skip) {
		return true;
	}
	skip = render(heart2, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart3, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart4, 100);  
	if (skip) {
		return true;
	}
	skip = render(heart5, 100);
	if (skip) {
		return true;
	}
	skip = render(heart6, 100);  
	if (skip) {
		return true;
	}
	return false;
}

