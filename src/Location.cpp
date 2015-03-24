#include "Location.h"

Location::Location(unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;

	// TODO validate loc is inside board here?
}

unsigned int Location::distance(Location* other) {
	return abs(this->x - other->x) + abs(this->y - other->y);
}
