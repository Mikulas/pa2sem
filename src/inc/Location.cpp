#include "Location.h"

unsigned int Location::distance(Location* other) {
	return abs(this->x - other->x) + abs(this->y - other->y);
}

bool Location::inLine(Location* other) {
	return this->x == other->x || this->y == other->y;
}
