/*
	IJnimation blockanim by Einstein
*/
int blockanim() {

	const PROGMEM byte ba1[8] = {
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111
	};

	const PROGMEM byte ba2[8] = {
		B00000000,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B00000000
	};

	const PROGMEM byte ba3[8] = {
		B00000000,
		B00000000,
		B00111100,
		B00111100,
		B00111100,
		B00111100,
		B00000000,
		B00000000
	};

	const PROGMEM byte ba4[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00011000,
		B00011000,
		B00000000,
		B00000000,
		B00000000
	};

	const PROGMEM byte ba5[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000
	};

	const PROGMEM byte ba6[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00011000,
		B00011000,
		B00000000,
		B00000000,
		B00000000
	};

	const PROGMEM byte ba7[8] = {
		B00000000,
		B00000000,
		B00111100,
		B00111100,
		B00111100,
		B00111100,
		B00000000,
		B00000000
	};

	const PROGMEM byte ba8[8] = {

		B00000000,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B01111110,
		B00000000
	};

	const PROGMEM byte ba9[8] = {

		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111
	};

	const PROGMEM byte ba10[8] = {

		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111,
		B11111111

	};
	bool skip;
	skip = render(ba1, 200);
	if (skip) {
		return true;
	}
	skip = render(ba2, 200);
	if (skip) {
		return true;
	} skip = render(ba3, 200);
	if (skip) {
		return true;
	} skip = render(ba4, 200);
	if (skip) {
		return true;
	} skip = render(ba5, 200);
	if (skip) {
		return true;
	} skip = render(ba6, 200);
	if (skip) {
		return true;
	} skip = render(ba7, 200);
	if (skip) {
		return true;
	} skip = render(ba8, 200);
	if (skip) {
		return true;
	} skip = render(ba9, 200);
	if (skip) {
		return true;
	}
	skip = render(ba10, 200);
	if (skip) {
		return true;
	}
	return false;
}
