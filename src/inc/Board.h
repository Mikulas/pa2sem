#ifndef BOARD
#define BOARD

class Board;

#include <vector>
#include "Game.h"
#include "Location.h"
#include "Ship.h"
#include "Player/Player.h"

using std::vector;


class Board
{
public:
	Board(const Game* game, Player* player);
	void setOpponent(Board* opponent) {
		this->opponent = opponent;
	};

	bool canPlace(const Ship* newShip) const;
	const Ship* isShipAt(const Location) const;
	const Ship* hit(const Location);
	bool allShipsSunk() const;
	void resetLocations();
	bool validate() const;

	vector<Ship> ships; // TODO fix visibility
	Player* getPlayer() const;
	const Game* getGame() const;

private:
	const Game* game;
	Player* player;
	Board* opponent;
};


#endif
