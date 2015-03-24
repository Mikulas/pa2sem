#ifndef SHIP
#define SHIP

#include <vector>
#include <string>
#include "Location.h"

using std::string;
using std::vector;


class Ship {
public:
	Ship(unsigned int length, string name) : name(name), length(length) {};
	bool setStartEnd(Location start, Location end);

	const string name;
	const unsigned int length;

private:
	vector<Location> fields;
};


#endif
