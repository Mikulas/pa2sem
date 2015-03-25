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
	vector<Ship> ships;
	bool canPlace(Ship* newShip);
	bool isShipAt(Location);
};


#endif
