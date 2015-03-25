#ifndef LOCATION
#define LOCATION

#define BOARD_SIZE 10

#include <exception>
#include <stdlib.h>

using std::exception;


class Location {
public:
	Location(unsigned int x, unsigned int y);
	const unsigned int x;
	const unsigned int y;

	inline bool operator==(const Location& rhs) {
		return this->x == rhs.x && this->y == rhs.y;
	}

	inline bool operator!=(const Location& rhs) {
		return !(*this == rhs);
	}

	/** for 0,0->3,4 intentionally returns 7, not 5 */
	unsigned int distance(Location*);
	bool inLine(Location*);
};


#endif
