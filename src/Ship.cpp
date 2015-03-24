#include "Ship.h"

Ship::Ship(string name, Location start, Location end) {
	this->name = name;

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
}
