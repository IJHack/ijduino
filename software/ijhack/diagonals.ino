
void diagonals() {
	byte diagonal1[8]={B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010};

	byte diagonal2[8]={B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101,
		B10101010,
		B01010101};

	bool skip = render(diagonal1, 500);
	if (skip) {
		return;
	}
	render(diagonal2, 500);
}
