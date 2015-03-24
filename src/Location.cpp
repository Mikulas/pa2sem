#include "Location.h"

unsigned int Location::distance(Location* other) {
	return abs(this->x - other->x) + abs(this->y - other->y);
}
