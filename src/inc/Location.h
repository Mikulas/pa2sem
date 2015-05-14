#ifndef LOCATION_H
#define LOCATION_H

#define BOARD_SIZE 10

#include <exception>
#include <stdlib.h>


/**
 * Thrown when coordinates are out of bounds
 */
class InvalidLocationException {};


/**
 * \exception InvalidLocationException
 *
 * All fields serialized into Payload
 * - `x`
 * - `y`
 */
class Location {
public:
	/**
	 * \throws InvalidLocationException if `x`, `y` are out of bounds
	 */
	Location(unsigned int x = 0, unsigned int y = 0);
	unsigned int x;
	unsigned int y;

	// <set> operators
	inline bool operator==(const Location &rhs) const {
		return this->getIndex() == rhs.getIndex();
	}

	inline bool operator!=(const Location &rhs) const {
		return this->getIndex() != rhs.getIndex();
	}

	inline bool operator<(const Location &rhs) const {
		return this->getIndex() < rhs.getIndex();
	}

	inline bool operator<=(const Location &rhs) const {
		return this->getIndex() <= rhs.getIndex();
	}

	inline bool operator>(const Location &rhs) const {
		return this->getIndex() > rhs.getIndex();
	}

	inline bool operator>=(const Location &rhs) const {
		return this->getIndex() >= rhs.getIndex();
	}

	/** for 0,0->3,4 intentionally returns 7, not 5 */
	unsigned int distance(const Location*) const;
	bool inLine(const Location*) const;

private:
	unsigned int getIndex() const;
};

#endif
