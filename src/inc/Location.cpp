#include "Location.h"

Location::Location(unsigned int x, unsigned int y) : x(x), y(y) {
	if (x >= BOARD_SIZE || y >= BOARD_SIZE) {
		throw new exception;
	}
}

unsigned int Location::getIndex() const {
	return this->y * BOARD_SIZE + this->x;
}

unsigned int Location::distance(const Location* other) const {
	return abs(this->x - other->x) + abs(this->y - other->y) + 1;
}

bool Location::inLine(const Location* other) const {
	return this->x == other->x || this->y == other->y;
}
