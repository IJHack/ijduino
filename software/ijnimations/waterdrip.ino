/*
	IJnimation waterdrip by Einstein
*/
int waterdrip() {
	const byte drip1[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111111,
		B11111111
	};


	const byte drip2[8] = {
		B00011000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111111,
		B11111111
	};

	const byte drip3[8] = {
		B00011000,
		B00011000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11111111,
		B11111111
	};

	const byte drip4[8] = {
		B00000000,
		B00011000,
		B00011000,
		B00000000,
		B00000000,
		B00000000,
		B11111111,
		B11111111
	};

	const byte drip5[8] = {
		B00000000,
		B00000000,
		B00011000,
		B00011000,
		B00000000,
		B00000000,
		B11111111,
		B11111111
	};

	const byte drip6[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00011000,
		B00011000,
		B00000000,
		B11111111,
		B11111111
	};
	const byte drip7[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00011000,
		B11111111,
		B11111111
	};

	const byte drip8[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B11100111,
		B11111111
	};

	const byte drip9[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00100100,
		B11011011,
		B11111111
	};

	const byte drip10[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B01011010,
		B10100001,
		B11111111
	};

	const byte drip11[8] = {
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B01111110,
		B11111111

	};

	bool skip;
	skip = render(drip1, 100);
	if (skip) {
		return true;
	}
	skip = render(drip2, 100);
	if (skip) {
		return true;
	}
	skip = render(drip3, 100);
	if (skip) {
		return true;
	}
	skip = render(drip4, 100);
	if (skip) {
		return true;
	}
	skip = render(drip5, 100);
	if (skip) {
		return true;
	}
	skip = render(drip6, 100);
	if (skip) {
		return true;
	}
	skip = render(drip7, 100);
	if (skip) {
		return true;
	}
	skip = render(drip8, 100);
	if (skip) {
		return true;
	}
	skip = render(drip9, 100);
	if (skip) {
		return true;
	}
	skip = render(drip10, 100);
	if (skip) {
		return true;
	}
	skip = render(drip11, 100);
	if (skip) {
		return true;
	}
	return false;
}
