#ifndef BOARD
#define BOARD

class Board;

#include <vector>
#include "Game.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"
#include "Player/Player.h"

using std::vector;


class Board
{
public:
#ifdef TESTMODE
	Board() {};
#endif
	Board(const Game* game, Player* player);
	void setOpponent(Board* opponent) {
		this->opponent = opponent;
	};

	bool canPlace(const Ship* newShip) const;
	const Ship* isShipAt(const Location&) const;
	const Ship* hit(const Location&);
	bool allShipsSunk() const;
	void resetLocations();
	bool validate() const;
	const Shot respond(const Location &loc);
	void setShips(vector<Ship>);

	vector<Ship> ships; // TODO fix visibility
	Player* getPlayer() const;
	const Game* getGame() const;

	Board* opponent; // TODO fix visibility

private:
	const Game* game;
	Player* player;
};


#endif
