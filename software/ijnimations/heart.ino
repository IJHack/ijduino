/*
	IJnimation heart by damnlie
*/
int heart() {

	/* here is the data for the characters */
	byte heart2[8]={B00000000,
		B01100110,
		B10011001,
		B10000001,
		B10000001,
		B01000010,
		B00100100,
		B00011000};

	/* here is the data for the characters */
	byte heart1[8]={
		B00000000,
		B01100110,
		B11111111,
		B11111111,
		B11111111,
		B01111110,
		B00111100,
		B00011000};

	bool skip = render(heart1, 500);
	if (skip) {
		return true;
	}
	skip = render(heart2, 500); 
	if (skip) {
		return true;
	}
	return false;
}

