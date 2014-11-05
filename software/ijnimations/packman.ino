/*
	IJnimation "packman" by damnlie
*/
int packman() {

	byte packman1[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};


	byte packman2[8]={
		B00000000,
		B00000000,
		B00000000,
		B10000000,
		B00000000,
		B00000000,
		B10000000,
		B00000000};


	byte packman3[8]={
		B00000000,
		B00000000,
		B10000000,
		B11000000,
		B00000000,
		B00000000,
		B11000000,
		B10000000};



	byte packman4[8]={
		B00000000,
		B10000000,
		B11000000,
		B11100000,
		B00000000,
		B00000000,
		B11100000,
		B11000000};



	byte packman5[8]={
		B00000000,
		B11000000,
		B01100000,
		B11110000,
		B10000000,
		B10000000,
		B11110000,
		B11100000};

	byte packman6[8]={
		B00000000,
		B11100000,
		B11110000,
		B01111000,
		B11000000,
		B11000000,
		B11111000,
		B11110000};


	byte packman7[8]={
		B00000000,
		B01110000,
		B11111000,
		B10111100,
		B11100000,
		B11100000,
		B11111100,
		B01111000};


	byte packman8[8]={
		B00000000,
		B00111000,
		B01111100,
		B11011110,
		B11110000,
		B11110000,
		B01111110,
		B00111100};

	byte packman9[8]={
		B00000000,
		B00011100,
		B00111110,
		B01101111,
		B01111000,
		B01111000,
		B00111111,
		B00011110};


	byte packman10[8]={
		B00000000,
		B00001110,
		B00011111,
		B00110111,
		B00111100,
		B00111100,
		B00011111,
		B00001111};


	byte packman11[8]={
		B00000000,
		B00000111,
		B00001111,
		B00011011,
		B00011110,
		B00011110,
		B00001111,
		B00000111};


	byte packman12[8]={
		B00000000,
		B00000011,
		B00000111,
		B00001101,
		B00001111,
		B00001111,
		B00000111,
		B00000011};



	byte packman13[8]={
		B00000000,
		B00000001,
		B00000011,
		B00000110,
		B00000111,
		B00000111,
		B00000011,
		B00000001};


	byte packman14[8]={
		B00000000,
		B00000000,
		B00000001,
		B00000011,
		B00000011,
		B00000011,
		B00000001,
		B00000000};



	byte packman15[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000001,
		B00000001,
		B00000001,
		B00000000,
		B00000000};


	byte packman16[8]={
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000};


	bool skip;
	skip = render(packman1, 200);  
	if (skip) {
		return true;
	}
	skip = render(packman2, 200);
	if (skip) {
		return true;
	}
	skip = render(packman3, 200);
	if (skip) {
		return true;
	}
	skip = render(packman4, 200);
	if (skip) {
		return true;
	}
	skip = render(packman5, 200);
	if (skip) {
		return true;
	}
	skip = render(packman6, 200);
	if (skip) {
		return true;
	}
	skip = render(packman7, 200);
	if (skip) {
		return true;
	}
	skip = render(packman8, 200);
	if (skip) {
		return true;
	}
	skip = render(packman9, 200);
	if (skip) {
		return true;
	}
	skip = render(packman10, 200);
	if (skip) {
		return true;
	}
	skip = render(packman11, 200);
	if (skip) {
		return true;
	}
	skip = render(packman12, 200);
	if (skip) {
		return true;
	}
	skip = render(packman13, 200);
	if (skip) {
		return true;
	}
	skip = render(packman14, 200);
	if (skip) {
		return true;
	}
	skip = render(packman15, 200);
	if (skip) {
		return true;
	} 
	skip = render(packman16, 200);
	if (skip) {
		return true;
	} 
	return false;
}
