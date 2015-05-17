#ifndef PONG_H
#define PONG_H

#include "Ball.h"
#include "Paddle.h"

class Pong
{
public:
    Pong(int rows, int cols, int paddle0_pin, int paddle1_pin) :
	MAX_ROW(rows - 1),
	MAX_COLUMN(cols - 1),
	paddle0_(paddle0_pin, (MAX_ROW / 2) - 1, 0),
	paddle1_(paddle1_pin, (MAX_ROW / 2) - 1, MAX_COLUMN),
	ball_(rows, cols),
	startPlayer_(0) {
	score_[0] = 0;
	score_[1] = 0;
    }

    void start();
    void update();

protected:
    const int MAX_ROW;
    const int MAX_COLUMN;

    void movePaddle(Paddle& p);
    bool moveBall();
    bool gameOver();

    virtual void showPaddle(Paddle& p) = 0;
    virtual void hidePaddle(Paddle& p) = 0;
    virtual void showBall(Ball& b) = 0;
    virtual void hideBall(Ball& b) = 0;
    virtual void showScore() = 0;
    virtual void startGame() = 0;

    Paddle paddle0_;
    Paddle paddle1_;
    Ball ball_;
    int startPlayer_;
    int score_[2];
    unsigned long t_, t0_, delay_;
};

#endif // PONG_H

// Local variables:
// mode: c++
// End:
