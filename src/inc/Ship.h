#ifndef SHIP
#define SHIP

#include <vector>
#include <string>
#include "Location.h"

using std::string;
using std::vector;


class Ship {
public:
	Ship(unsigned int length) : length(length) {}
	Ship(unsigned int length, string name) : name(name), length(length) {}
	bool setStartEnd(Location start, Location end);
	bool overlaps(Ship*);
	bool isPlaced();

	const string name;
	const unsigned int length;

protected:
	vector<Location> fields;
};


#endif
