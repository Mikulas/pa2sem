#ifndef SHIP
#define SHIP

#include <set>
#include <string>
#include "Location.h"

using std::string;
using std::set;


class Ship {
public:
	Ship(unsigned int length) : length(length) {}
	Ship(unsigned int length, string name) : name(name), length(length) {}
	bool setStartEnd(Location start, Location end);
	bool overlaps(Ship*);
	bool overlaps(Location);
	bool isPlaced();
	bool hit(Location);
	bool isSunk();

	const string name;
	const unsigned int length;

protected:
	set<Location> fields;
	set<Location> hits;
};


#endif
