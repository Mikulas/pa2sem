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

	/** for 0,0->3,4 intentionally returns 7, not 5 */
	unsigned int distance(Location*);
	bool inLine(Location*);
};


#endif
