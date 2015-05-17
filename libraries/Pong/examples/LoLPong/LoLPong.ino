#include "Pong.h"

// LoLShield library:
//
// https://code.google.com/p/lolshield/

#include "Charliplexing.h"
#include "Myfont.h"

static const int PADDLE0_PIN = 4;
static const int PADDLE1_PIN = 5;

int digit[][7] = {
    { 0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110 },
    { 0b00100, 0b00110, 0b00100, 0b00100, 0b00100, 0b00100, 0b01110 },
    { 0b01110, 0b10001, 0b10000, 0b01110, 0b00001, 0b00001, 0b11111 },
    { 0b01110, 0b10001, 0b10000, 0b01110, 0b10000, 0b10001, 0b01110 },
    { 0b01000, 0b01100, 0b01010, 0b01001, 0b11111, 0b01000, 0b01000 },
    { 0b11111, 0b00001, 0b00001, 0b01111, 0b10000, 0b10000, 0b01111 },
    { 0b01110, 0b10001, 0b00001, 0b01111, 0b10001, 0b10001, 0b01110 },
    { 0b11111, 0b10000, 0b01000, 0b01000, 0b00100, 0b00100, 0b00100 },
    { 0b01110, 0b10001, 0b10001, 0b01110, 0b10001, 0b10001, 0b01110 },
    { 0b01110, 0b10001, 0b10001, 0b11110, 0b10000, 0b10000, 0b01111 },
};

class LoLShieldPong : public Pong
{
public:
    LoLShieldPong(int paddle0_pin, int paddle1_pin) :
	Pong(DISPLAY_ROWS, DISPLAY_COLS, paddle0_pin, paddle1_pin) {}

    void showPaddle(Paddle& p) { setPaddle(p, true);  }
    void hidePaddle(Paddle& p) { setPaddle(p, false); }

    void showBall(Ball& b) { LedSign::Set(b.col(), b.row(), true); }
    void hideBall(Ball& b) { LedSign::Set(b.col(), b.row(), false); }

    void startGame();
    void showScore();

private:
    static const unsigned char banner[];
    static const int bannerlength;

    void setPaddle(const Paddle& p, bool state);
};

const unsigned char LoLShieldPong::banner[] = "Play PONG!";
const int LoLShieldPong::bannerlength = 10;

void LoLShieldPong::startGame()
{
    LedSign::Clear();
    LedSign::SetBrightness(50);

    Myfont::Banner(bannerlength, const_cast<unsigned char*>(banner));
    start();
}

void LoLShieldPong::showScore()
{
    int i, j, ps1, ps2;

    // From the LoLShield example pong2.pde
    // 
    // Author  : Benjamin Sonntag http://benjamin.sonntag.fr
    // Modified: Matt Mets http://cibomahto.com

    for (ps1 = 0; ps1 < 8; ps1++) {
	LedSign::Clear();  // Clear the active screen

	LedSign::Set(6, 4, 1); // dash between the scores
	LedSign::Set(7, 4, 1);

	// Fill it with both scores :
	// Left score goes up > down
	i = ps1;
	j = 6;
	while (i >= 0 && j >= 0) {
	    for (uint8_t k = 0; k < 5; k++) {
		LedSign::Set(k, i, (digit[score_[0]][j] >> k) & 1);
	    }
	    i--; j--;
	}

	// Right score goes down > up
	ps2 = 8 - ps1;
	i = ps2;
	j = 0;
	while (i <= 8 && j <= 6) {
	    for (uint8_t k = 0; k < 5; k++) {
		LedSign::Set(k + 9, i, (digit[score_[1]][j] >> k) & 1);
	    }
	    i++; j++;
	}

	delay(200);
    }

    delay(1500);
    LedSign::Clear(0);
}

void LoLShieldPong::setPaddle(const Paddle& p, bool state)
{
    LedSign::Set(p.col(), p.row(), state);
    LedSign::Set(p.col(), p.row() + 1, state);
}

LoLShieldPong pong(PADDLE0_PIN, PADDLE1_PIN);

void setup()
{
    LedSign::Init();
    pong.startGame();
}

void loop()
{
    pong.update();
}

// Local variables:
// mode: c++
// End:
