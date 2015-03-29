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
	/**
	 * \return random valid location
	 */
	static Location location() {
		return Location(coord(), coord());
	}
	/**
	 * \return random valid location for specified distance
	 * of another location
	 *
	 * Useful for placing random ships.
	 */
	static Location location(Location loc, unsigned int distance) {
		distance--;
	tryAgain:
		switch (between(0, 3)) {
			case 0:
				if (loc.y - distance >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x, loc.y - distance);
			case 1:
				if (loc.y + distance >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x, loc.y + distance);
			case 2:
				if (loc.x - distance >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x - distance, loc.y);
			case 3:
			default:
				if (loc.x + distance >= BOARD_SIZE) goto tryAgain;
				return Location(loc.x + distance, loc.y);
		}
	}
};


#endif
