/*
	IJnimation jumper byrealitygaps
*/
int jumper() {
	byte jumpdown[8]={
		B00111100,
		B00111100,
		B00011000,
		B01111110,
		B00011000,
		B00011000,
		B00100100,
		B00100100};

	byte jumpup[8]={
		B00111100,
		B01011010,
		B00111100,
		B00011000,
		B00011000,
		B00100100,
		B01000010,
		B00000000};

	bool skip = render(jumpdown, 500);
	if (skip) {
		return true;
	}
	skip = render(jumpup, 500);  
	if (skip) {
		return true;
	}
	return false;
}
