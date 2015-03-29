#ifndef BOARD
#define BOARD

#include <vector>
#include "Location.h"
#include "Ship.h"

using std::vector;


class Board
{
public:
	Board();
	vector<Ship> ships; // TODO fix visibility
	bool canPlace(const Ship* newShip) const;
	const Ship* isShipAt(const Location) const;
	const Ship* hit(const Location);
	bool allShipsSunk() const;
};


#endif
