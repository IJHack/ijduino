#include "Pong.h"

// LedControl library:
//
// http://playground.arduino.cc/Main/LedControl
// http://www.wayoda.org/arduino/ledcontrol/index.html

#include "LedControl.h"

static const int DATA_PIN = 12;
static const int CLK_PIN  = 11;
static const int CS_PIN   = 10;

static const int PADDLE0_PIN = 0;
static const int PADDLE1_PIN = 1;

static char pongchars[][8] = {
    { 0b00000000, 0b01111100, 0b01000010, 0b01000010,   
      0b01111100, 0b01000000, 0b01000000, 0b00000000, }, // P
    { 0b00000000, 0b00111100, 0b01000010, 0b01000010,   
      0b01000010, 0b01000010, 0b00111100, 0b00000000, }, // O
    { 0b00000000, 0b01000010, 0b01100010, 0b01010010,   
      0b01001010, 0b01000110, 0b01000010, 0b00000000, }, // N
    { 0b00000000, 0b00111100, 0b01000000, 0b01000000,   
      0b01111100, 0b01000010, 0b00111100, 0b00000000, }, // G
};

static char digit[][5] = {
    { 0b111, 0b101, 0b101, 0b101, 0b111 },
    { 0b001, 0b001, 0b001, 0b001, 0b001 },
    { 0b111, 0b001, 0b111, 0b100, 0b111 },
    { 0b111, 0b001, 0b111, 0b001, 0b111 },
    { 0b101, 0b101, 0b111, 0b001, 0b001 },
    { 0b111, 0b100, 0b111, 0b001, 0b111 },
    { 0b111, 0b100, 0b111, 0b101, 0b111 },
    { 0b111, 0b001, 0b001, 0b001, 0b001 },
    { 0b111, 0b101, 0b111, 0b101, 0b111 },
    { 0b111, 0b101, 0b111, 0b001, 0b111 },
};

class LedMatrixPong : public Pong
{
public:
    LedMatrixPong(LedControl& ledControl, int paddle0_pin, int paddle1_pin) :
	ledControl_(ledControl),
	Pong(ROWS, COLS, paddle0_pin, paddle1_pin) {}

    void showPaddle(Paddle& p) { setPaddle(p, true); }
    void hidePaddle(Paddle& p) { setPaddle(p, false); }

    void showBall(Ball& b) { ledControl_.setLed(0, b.row(), b.col(), true); }
    void hideBall(Ball& b) { ledControl_.setLed(0, b.row(), b.col(), false); }

    void startGame();
    void showScore();

private:
    static const int ROWS = 8;
    static const int COLS = 8;

    void sayPong(int delay_ms);
    void setPaddle(const Paddle& p, bool state);

    LedControl& ledControl_;
};

void LedMatrixPong::startGame()
{
    ledControl_.clearDisplay(0);
    sayPong(500);

    for (int row = MAX_ROW; row >= 0; row--) {
	ledControl_.setRow(0, row, 0xff);
	delay(100);
	ledControl_.setRow(0, row, 0);
    }

    start();
}

void LedMatrixPong::sayPong(int delay_ms)
{
    for (int c = 0; c < 4; c++) {
	for (int r = 0; r <= MAX_ROW; r++) {
	    ledControl_.setRow(0, r, pongchars[c][r]);
	}
	delay(delay_ms);
    }
}

void LedMatrixPong::showScore()
{
    for (int step = 0; step < 10; step++) {
	ledControl_.clearDisplay(0);
	ledControl_.setLed(0, 3, 3, true);
	ledControl_.setLed(0, 3, 4, true);

	int i = (step < 8) ? step : 14 - step;
	int j = 4;
	while (i >= 0 && j >= 0) {
	    for (int k = 0; k < 3; k++) {
		ledControl_.setLed(0, i, 2 - k, digit[score_[0]][j] & (1<<k));
	    }
	    i--; j--;
	}

	i = (step < 9) ? 8 - step : step - 8;
	j = 0;
	while (i <= 7 && j <= 4) {
	    for (int k = 0; k < 3; k++) {
		ledControl_.setLed(0, i, 7 - k, digit[score_[1]][j] & (1<<k));
	    }
	    i++; j++;
	}
	
	delay(50 + 10 * step);
    }

    delay(1500);
    ledControl_.clearDisplay(0);
}

void LedMatrixPong::setPaddle(const Paddle& p, bool state)
{
    ledControl_.setLed(0, p.row(), p.col(), state);
    ledControl_.setLed(0, p.row() + 1, p.col(), state);
}

LedControl ledControl(DATA_PIN, CLK_PIN, CS_PIN, 1);
LedMatrixPong pong(ledControl, PADDLE0_PIN, PADDLE1_PIN);

void setup()
{
    ledControl.shutdown(0, false);
    ledControl.setIntensity(0, 15);
    ledControl.clearDisplay(0);
    randomSeed(analogRead(0));

    pong.startGame();
}

void loop()
{
    pong.update();
}

// Local variables:
// mode: c++
// End:
