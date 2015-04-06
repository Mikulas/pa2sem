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
	bool setStartEnd(const Location start, const Location end);
	void unplace();
	bool overlaps(const Ship*) const;
	bool overlaps(const Location) const;
	bool isPlaced() const;
	bool hit(const Location);
	bool isSunk() const;

	const string name;
	const unsigned int length;

protected:
	set<Location> fields;
	set<Location> hits;
};


#endif
