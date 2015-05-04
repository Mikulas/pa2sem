#include "Location.h"

Location::Location(unsigned int x, unsigned int y) : x(x), y(y) {
	if (x >= BOARD_SIZE || y >= BOARD_SIZE) {
		throw InvalidLocationException();
	}
}

unsigned int Location::getIndex() const {
	return this->y * BOARD_SIZE + this->x;
}

unsigned int Location::distance(const Location* other) const {
	return abs((int) this->x - (int) other->x) + abs((int) this->y - (int) other->y) + 1;
}

bool Location::inLine(const Location* other) const {
	return this->x == other->x || this->y == other->y;
}
