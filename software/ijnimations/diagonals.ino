/*
	IJnimation 'diagonals' by Yvette Cendes
*/
int diagonals() {
	const PROGMEM byte diagonal1[8]={B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010};

	const PROGMEM byte diagonal2[8]={B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101};

	bool skip = render(diagonal1, 500);
	if (skip) {
		return true;
	}
	skip = render(diagonal2, 500);
	if (skip) {
		return true;
	}
	return false;
}
