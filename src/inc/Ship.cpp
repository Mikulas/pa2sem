#include "Ship.h"

bool Ship::setStartEnd(Location start, Location end) {
	if (fields.size() != 0) {
		return false;
	}
	
	if (!start.inLine(&end) || start.distance(&end) != this->length) {
		return false;
	}

	unsigned int i;
	short int step;
	if (start.x == end.x) {
		step = start.y < end.y ? 1 : -1;
		for (i = start.y; i < end.y; i += step) {
			fields.push_back(Location(start.x, i));
		}

	} else {
		step = start.x < end.x ? 1 : -1;
		for (i = start.x; i < end.x; i += step) {
			fields.push_back(Location(i, start.y));
		}
	}

	return true;
}
