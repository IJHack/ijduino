#include <Arduino.h>

#include "Ball.h"

int Ball::randomAngle(int row)
{
    int angle = random(1, 4) * 45;

    if ((row == 0 && angle < 90) ||
	(row == 7 && angle > 90))
	angle = 90;

    return angle;
}

unsigned long Ball::accelerate(unsigned long delay)
{
    if (MIN_DELAY + DELAY_STEP <= delay)
    	delay -= DELAY_STEP;

    return delay;
}

bool Ball::move(Paddle& paddle0, Paddle& paddle1, unsigned long& delay, int &startPlayer)
{
    bool carryOn = true;

    if (angle_ > 0) {
	col_++;
    } else {
	col_--;
    }

    if (col_ == MAX_COLUMN) {
	if (paddle1.hit(row_, col_)) {
	    col_ = MAX_COLUMN - 2;
	    angle_ = -randomAngle(row_);
	    delay = accelerate(delay);
	} else {
	    carryOn = false;
	    startPlayer = 0;
	}
    } else if (col_ == MIN_COLUMN) {
	if (paddle0.hit(row_, col_)) {
	    col_ = MIN_COLUMN + 2;
	    angle_ = randomAngle(row_);
	    delay = accelerate(delay);
	} else {
	    carryOn = false;
	    startPlayer = 1;
	}
    } else if (row_ == MIN_ROW) {
	if (abs(angle_) < 90) {
	    angle_ *= 3;
	}
    } else if (row_ == MAX_ROW) {
	if (abs(angle_) > 90) {
	    angle_ /= 3;
	}
    }

    if (abs(angle_) > 90) {
	row_++;
    } else if (abs(angle_) < 90) {
	row_--;
    }

    return carryOn;
}

// Local variables:
// mode: c++
// End:
