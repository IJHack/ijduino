/*
	IJnimation Arrows by Realitygaps
*/
int arrows() {
	const byte arrowup[8]={
		B00000000,
		B00011000,
		B00111100,
		B01111110,
		B00011000,
		B00011000,
		B00011000,
		B00000000};

	const byte arrowdown[8]={
		B00000000,
		B00011000,
		B00011000,
		B00011000,
		B01111110,
		B00111100,
		B00011000,
		B00000000};

	const byte arrowright[8]={
		B00000000,
		B00001000,
		B00001100,
		B01111110,
		B01111110,
		B00001100,
		B00001000,
		B00000000};


	const byte arrowleft[8]={
		B00000000,
		B00010000,
		B00110000,
		B01111110,
		B01111110,
		B00110000,
		B00010000,
		B00000000};

	bool skip;
	skip = render(arrowup, 200);
	if (skip) {
		return true;
	}
	skip = render(arrowright, 200);  
	if (skip) {
		return true;
	}
	skip = render(arrowdown, 200);  
	if (skip) {
		return true;
	}
	skip = render(arrowleft, 200);  
	if (skip) {
		return true;
	}
	return false;
}

