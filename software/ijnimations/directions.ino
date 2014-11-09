/*
	IJnimation directions by realitygaps
*/
int directions() {
	const byte directions1[8]={
		B00000000,
		B00000000,
		B00000000,
		B10000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};

	const byte directions2[8]={
		B00000000,
		B00000000,
		B10000000,
		B01000000,
		B10000000,
		B00000000,
		B00000000,
		B00000000};

	const byte directions3[8]={
		B00000000,
		B10000000,
		B01000000,
		B00100000,
		B01000000,
		B10000000,
		B00000000,
		B00000000};

	const byte directions4[8]={
		B10000000,
		B01000000,
		B00100000,
		B00010000,
		B00100000,
		B01000000,
		B10000000,
		B00000000};

	const byte directions5[8]={
		B01000000,
		B00100000,
		B00010000,
		B00001000,
		B00010000,
		B00100000,
		B01000000,
		B00000000};

	const byte directions6[8]={
		B00100000,
		B00010000,
		B00001000,
		B00000100,
		B00001000,
		B00010000,
		B00100000,
		B00000000};

	const byte directions7[8]={
		B00010000,
		B00001000,
		B00000100,
		B00000010,
		B00000100,
		B00001000,
		B00010000,
		B00000000};

	const byte directions8[8]={
		B00001000,
		B00000100,
		B00000010,
		B00000001,
		B00000010,
		B00000100,
		B00001000,
		B00000000};

	const byte directions9[8]={
		B00000100,
		B00000010,
		B00000001,
		B00000000,
		B00000001,
		B00000010,
		B00000100,
		B00000000};

	const byte directions10[8]={
		B00000010,
		B00000001,
		B00000000,
		B00000000,
		B00000000,
		B00000001,
		B00000010,
		B00000000};

	const byte directions11[8]={
		B00000001,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000001,
		B00000000};

	const byte directions12[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};

	bool skip;
	skip = render(directions1, 200);
	if (skip) {
		return true;
	}
	skip = render(directions2, 200);
	if (skip) {
		return true;
	}
	skip = render(directions3, 200);
	if (skip) {
		return true;
	}
	skip = render(directions4, 200);
	if (skip) {
		return true;
	}
	skip = render(directions5, 200);
	if (skip) {
		return true;
	}
	skip = render(directions6, 200);
	if (skip) {
		return true;
	}
	skip = render(directions7, 200);
	if (skip) {
		return true;
	}
	skip = render(directions8, 200);
	if (skip) {
		return true;
	}
	skip = render(directions9, 200);
	if (skip) {
		return true;
	}
	skip = render(directions10, 200);
	if (skip) {
		return true;
	}
	skip = render(directions11, 200);
	if (skip) {
		return true;
	}
	skip = render(directions12, 200);
	if (skip) {
		return true;
	}
	return false;
}
