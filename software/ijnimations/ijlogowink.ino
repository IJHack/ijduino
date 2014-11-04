
void ijlogowink() {
	byte logowink0[8]={
		B11000011,
		B11000011,
		B00000000,
		B00000011,
		B11000011,
		B11100111,
		B01111110,
		B00111100};

	byte logowink1[8]={  
		B00000011,
		B00000011,
		B00000000,
		B00000011,
		B11000011,
		B11100111,
		B01111110,
		B00111100};

	byte logowink2[8]={  
		B11000000,
		B11000000,
		B00000000,
		B00000011,
		B11000011,
		B11100111,
		B01111110,
		B00111100};

	byte logowink3[8]={  
		B11000011,
		B11000011,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};

	bool skip;
	skip = render(logowink0, 500);
	if (skip) {
		return;
	}
	skip = render(logowink1, 500);
	if (skip) {
		return;
	}
	skip = render(logowink0, 500);
	if (skip) {
		return;
	}  
	skip = render(logowink2, 500);
	if (skip) {
		return;
	}
	skip = render(logowink0, 500);
	if (skip) {
		return;
	}
	skip = render(logowink3, 500);  
}
