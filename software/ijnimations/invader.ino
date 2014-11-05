/*
	First IJnimation "invader" by realitygaps
*/
int invader() {
	byte invade[8]={
		B00100100,
		B00100100,
		B01111110,
		B11011011,
		B11111111,
		B11111111,
		B10100101,
		B00100100};

	byte devade[8]={
		B00100100,
		B10100101,
		B11111111,
		B11011011,
		B11111111,
		B01111110,
		B00100100,
		B00100100};

	bool skip = render(invade, 500);
	if (skip) {
		return true;
	}
	skip = render(devade, 500);
	if (skip) {
		return true;
	}
	return false;	
}
