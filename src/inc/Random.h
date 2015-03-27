#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include "Location.h"


class Random {
public:
	static unsigned int between(unsigned int min, unsigned int max) {
		return min + rand() % max + 1;
	}
	static unsigned int coord() {
		return between(0, BOARD_SIZE - 1);
	}
	static Location location() {
		return Location(coord(), coord());
	}
	static Location location(Location loc, unsigned int length) {
		length--;
	tryAgain:
		switch (between(0, 3)) {
			case 0:
				if (loc.y - length >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x, loc.y - length);
			case 1:
				if (loc.y + length >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x, loc.y + length);
			case 2:
				if (loc.x - length >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x - length, loc.y);
			case 3:
			default:
				if (loc.x + length >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x + length, loc.y);
		}
	}
};


#endif
