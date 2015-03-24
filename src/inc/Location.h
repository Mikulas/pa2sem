#ifndef LOCATION
#define LOCATION

#include <stdlib.h>


class Location {
public:
	Location(unsigned int x, unsigned int y) : x(x), y(y) {};
	const unsigned int x;
	const unsigned int y;

	/** for 0,0->3,4 intentionally returns 7, not 5 */
	unsigned int distance(Location*);
	bool inLine(Location*);
};


#endif
