#include "Ship.h"

bool Ship::isPlaced() const {
	return fields.size() != 0;
}

bool Ship::overlaps(const Ship* other) const {
	for (auto &field : this->fields) {
		if (other->overlaps(field)) {
			return true;
		}
	}
	return false;
}

bool Ship::overlaps(const Location loc) const {
	return fields.find(loc) != fields.end();
}

bool Ship::setStartEnd(const Location start, const Location end) {
	if (!start.inLine(&end) || start.distance(&end) != this->length) {
		return false;
	}
	fields.clear();

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

void Ship::unplace() {
	fields.clear();
}

bool Ship::hit(const Location loc) {
	if (fields.find(loc) == fields.end()) {
		return false;
	}
	hits.insert(loc);
	return true;
}

bool Ship::isSunk() const {
	return hits.size() == fields.size();
}
