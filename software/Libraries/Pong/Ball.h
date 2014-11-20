#ifndef BALL_H
#define BALL_H

#include "Paddle.h"

class Ball {
public:
    Ball(int rows, int cols) :
	MIN_ROW(0),
	MIN_COLUMN(0),
	MAX_ROW(rows - 1),
	MAX_COLUMN(cols - 1) {}

    static const unsigned long MIN_DELAY = 50;
    static const unsigned long MAX_DELAY = 300;
    static const unsigned long DELAY_STEP = 10;

    int row() const { return row_; }
    int col() const { return col_; }

    void setPosition(int row, int col, int angle) {
	row_ = row;
	col_ = col;
	angle_ = angle;
    }

    bool move(Paddle& paddle0, Paddle& paddle1, unsigned long& delay, int &startPlayer);

private:
    const int MIN_ROW, MIN_COLUMN;
    const int MAX_ROW, MAX_COLUMN;

    int randomAngle(int row);
    unsigned long accelerate(unsigned long delay);

    int row_;
    int col_;
    int angle_;
};

#endif // BALL_H

// Local variables:
// mode: c++
// End:
