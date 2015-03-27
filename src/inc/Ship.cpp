#include "Ship.h"

bool Ship::isPlaced() {
	return fields.size() != 0;
}

bool Ship::overlaps(Ship* other) {
	for (auto &field : this->fields) {
		if (other->overlaps(field)) {
			return true;
		}
	}
	return false;
}

bool Ship::overlaps(const Location loc) {
	return fields.find(loc) != fields.end();
}

bool Ship::setStartEnd(Location start, Location end) {
	if (fields.size() != 0) {
		return false;
	}

	if (!start.inLine(&end) || start.distance(&end) != this->length) {
		return false;
	}

	unsigned int i;
	short int min, max;
	if (start.x == end.x) {
		min = start.y < end.y ? start.y : end.y;
		max = start.y < end.y ? end.y : start.y;
		for (i = min; i <= max; i++) {
			fields.insert(Location(start.x, i));
		}

	} else {
		min = start.x < end.x ? start.x : end.x;
		max = start.x < end.x ? end.x : start.x;
		for (i = min; i <= max; i++) {
			fields.insert(Location(i, start.y));
		}
	}

	return true;
}

bool Ship::hit(Location loc) {
	if (fields.find(loc) == fields.end()) {
		return false;
	}
	hits.insert(loc);
	return true;
}

bool Ship::isSunk() {
	return hits.size() == fields.size();
}
