#ifndef SHIP
#define SHIP

#include <set>
#include <string>
#include "Location.h"

using std::string;
using std::set;


/**
 * Principal game piece
 *
 * Fields serialized into Payload:
 * - `length`
 * - `name`
 * - `start`
 * - `end`
 *
 * \warning `hits` are not serialized because they
 * should never leave server.
 */
class Ship {
public:
	Ship() {}
	Ship(unsigned int length) : length(length) {}
	Ship(unsigned int length, string name) : name(name), length(length) {}
	/**
	 * Effectively places ship on Board
	 */
	bool setStartEnd(const Location &start, const Location &end);
	/**
	 * Resets fields, which in turn resets isPlaced()
	 */
	void unplace();
	bool overlaps(const Ship*) const;
	bool overlaps(const Location&) const;
	/**
	 * \returns 'true' if setStartEnd has been called with valid locations
	 */
	bool isPlaced() const;
	/**
	 * Adds Location to `hits` if hit
	 * \returns boolean if Location overlaps any of this ships fields.
	 */
	bool hit(const Location&);
	/**
	 * \returns 'true' if all fields have been hit()
	 */
	bool isSunk() const;

	string name; // todo make const or fix visibility
	/**
	 * Amount of fields occupied. For example, ship of
	 * length 2 could be on fields (1, 1) to (1, 2).
	 */
	unsigned int length; // todo make const or fix visibility
	/**
	 * \internal
	 */
	Location start; // add getter
	/**
	 * \internal
	 */
	Location end; // add getter

protected:
	set<Location> fields;
	set<Location> hits;
};


#endif
