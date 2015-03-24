#ifndef SHIP
#define SHIP

#include <vector>
#include <string>
#include "Location.h"

using std::string;
using std::vector;


class Ship {
public:
	Ship(string name, Location start, Location end);

private:
	string name;
	vector<Location> fields;
};


#endif
