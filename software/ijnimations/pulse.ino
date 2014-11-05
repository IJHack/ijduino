/*
	IJnimation pulse by Einstein
*/
int pulse() {
	byte bigHeart[] = {
		B01100110,
		B11111111,
		B11111111,
		B11111111,
		B01111110,
		B00111100,
		B00011000,
		B00000000};

	byte smallHeart[] = {
		B00000000,
		B00000000,
		B00010100,
		B00111110,
		B00111110,
		B00011100,
		B00001000,
		B00000000};

	bool skip = render(bigHeart, 500);
	if (skip) {
		return true;
	}
	skip = render(smallHeart, 500);
	if (skip) {
		return true;
	}
	return false;
}
