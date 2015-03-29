#ifndef LOCATION
#define LOCATION

#define BOARD_SIZE 10

#include <exception>
#include <stdlib.h>

using std::exception;


class Location {
public:
	Location(unsigned int x, unsigned int y);
	const unsigned int x;
	const unsigned int y;

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
