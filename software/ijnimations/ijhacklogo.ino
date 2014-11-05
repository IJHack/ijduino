/*
	IJnimation IJHACK by Einstein, damnlie, the_JinX	
*/
int ijhacklogo() {
	/* here is the data for the characters */
	byte ij[8]={
		B11000011,
		B11000011,
		B00000000,
		B00000011,
		B11000011,
		B11100111,
		B01111110,
		B00111100};

	byte h[8]={
		B11000011,
		B11000011,
		B11000011,
		B11111111,
		B11111111,
		B11000011,
		B11000011,
		B11000011 };

	byte a[8]={
		B00011000,
		B00111100,
		B01100110,
		B11000011,
		B11111111,
		B11111111,
		B11000011,
		B11000011 };

	byte c[8]={
		B01111110,
		B11111111,
		B11000011,
		B11000000,
		B11000000,
		B11000011,
		B11111111,
		B01111110 };

	byte k[8]={
		B11000111,
		B11011110,
		B11111100,
		B11110000,
		B11110000,
		B11111100,
		B11011110,
		B11000111
	};

	bool skip;
	skip = render(ij, 500);
	if (skip) {
		return true;
	}
	skip = render(h, 500);
	if (skip) {
		return true;
	}
	skip = render(a, 500);
	if (skip) {
		return true;
	}
	skip = render(c, 500);
	if (skip) {
		return true;
	}
	skip = render(k, 500);
	if (skip) {
		return true;
	}
	return false;
}
