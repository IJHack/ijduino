/*
	IJnimation invadesuid by realitygaps
*/
int invadesquid() {
	byte invadesquid[8]={
		B00011000,
		B00111100,
		B01111110,
		B11011011,
		B11111111,
		B01011010,
		B10000001,
		B01000010};

	byte devadesquid[8]={
		B00011000,
		B00111100,
		B01111110,
		B11011011,
		B11111111,
		B00100100,
		B01011010,
		B10100101};

	bool skip = render(invadesquid, 500);
	if (skip) {
		return true;
	}
	skip = render(devadesquid, 500);  
	if (skip) {
		return true;
	}
	return false;
}

