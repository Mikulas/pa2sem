#include "Location.h"

Location::Location(unsigned int x, unsigned int y) : x(x), y(y) {
	if (x >= BOARD_SIZE || y >= BOARD_SIZE) {
		throw new exception;
	}
}

unsigned int Location::distance(Location* other) {
	return abs(this->x - other->x) + abs(this->y - other->y);
}

bool Location::inLine(Location* other) {
	return this->x == other->x || this->y == other->y;
}
