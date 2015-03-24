#ifndef LOCATION
#define LOCATION

#include <stdlib.h>


class Location {
public:
	Location(unsigned int x, unsigned int y) : y(y), x(x) {};
	const unsigned int x;
	const unsigned int y;

	unsigned int distance(Location*);
};


#endif
