#ifndef LOCATION
#define LOCATION

#include <stdlib.h>


class Location {
public:
	Location(unsigned int x, unsigned int y) : x(x), y(y) {};
	const unsigned int x;
	const unsigned int y;

	unsigned int distance(Location*);
	bool inLine(Location*);
};


#endif
