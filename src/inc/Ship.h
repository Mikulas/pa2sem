#ifndef SHIP
#define SHIP

#include <set>
#include <string>
#include "Location.h"

using std::string;
using std::set;


class Ship {
public:
	Ship() {}
	Ship(unsigned int length) : length(length) {}
	Ship(unsigned int length, string name) : name(name), length(length) {}
	bool setStartEnd(const Location start, const Location end);
	void unplace();
	bool overlaps(const Ship*) const;
	bool overlaps(const Location) const;
	bool isPlaced() const;
	bool hit(const Location);
	bool isSunk() const;

	string name; // todo make const or fix visibility
	unsigned int length; // todo make const or fix visibility
	Location start; // add getter
	Location end; // add getter

protected:
	set<Location> fields;
	set<Location> hits;
};


#endif
