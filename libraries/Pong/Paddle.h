#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    Paddle(int pin, int row, int col) :
	pin_(pin), row_(row), col_(col) {}

    void row(int row) { row_ = row; }

    bool hit(int row, int col) const {
	return col == col_ && (row == row_ || row == row_ + 1);
    }

    int pin() const { return pin_; }
    int row() const { return row_; }
    int col() const { return col_; }

private:
    int pin_;
    int row_;
    const int col_;
};

#endif // PADDLE_H

// Local variables:
// mode: c++
// End:
