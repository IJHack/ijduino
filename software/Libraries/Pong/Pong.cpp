#include <Arduino.h>

#include "Pong.h"

void Pong::start()
{
    if (startPlayer_ == 0) {
	ball_.setPosition(4, 1, 90);
    } else {
	ball_.setPosition(4, MAX_COLUMN - 1, -90);
    }

    showBall(ball_);
    t_ = t0_ = millis();
    delay_ = Ball::MAX_DELAY;
}

void Pong::update()
{
    movePaddle(paddle0_);
    movePaddle(paddle1_);

    if ((t_ = millis()) - t0_ > delay_) {
	if (!moveBall()) {
	    if (gameOver()) {
		startGame();
	    } else {
		showScore();
		start();
	    }
	} else {
	    t0_ = t_;
	}
    }
}

void Pong::movePaddle(Paddle& p)
{
    int row1 = map(analogRead(p.pin()), 0, 1000, 0, MAX_ROW - 1);
    int row2 = map(analogRead(p.pin()), 0, 1000, 0, MAX_ROW - 1);

    int row = (row1 + row2) / 2;

    if (row != p.row()) {
	hidePaddle(p);
	p.row(row);
    }
    showPaddle(p);
}

bool Pong::moveBall()
{
    hideBall(ball_);

    bool carryOn = ball_.move(paddle0_, paddle1_, delay_, startPlayer_);

    if (carryOn) {
	showBall(ball_);
    } else {
	score_[startPlayer_]++;
    }

    return carryOn;
}

bool Pong::gameOver()
{
    if (score_[0] > 9 || score_[1] > 9) {
	// show winner
	score_[0] = 0;
	score_[1] = 0;
	return true;
    }

    return false;
}
