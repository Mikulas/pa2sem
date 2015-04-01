#ifndef BOARD
#define BOARD

class Board;

#include <vector>
#include "Location.h"
#include "Ship.h"
#include "Player/Player.h"

using std::vector;


class Board
{
public:
	Board(Player* player);
	vector<Ship> ships; // TODO fix visibility
	bool canPlace(const Ship* newShip) const;
	const Ship* isShipAt(const Location) const;
	const Ship* hit(const Location);
	bool allShipsSunk() const;
	Player* getPlayer() const;

private:
	Player* player;
};


#endif
