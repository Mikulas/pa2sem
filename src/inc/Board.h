#ifndef BOARD_H
#define BOARD_H

class Board;

#include <vector>
#include "Game.h"
#include "Location.h"
#include "Player/Player.h"
#include "Ship.h"
#include "Shot.h"

using std::vector;


/**
 * Holds all Ship instances for a single Player.
 *
 * \warning As it enforces many game rules, Board instances
 * should never be networked without subsquent serverside
 * validation.
 */
class Board {
public:
#ifdef TESTMODE
	Board() {
		player = nullptr;
	};
#endif
	Board(const Game* game, Player* player);
	~Board();

	/**
	 * \returns `true` if Ship placement is valid
	 * in regard to other placed ships on this Board
	 */
	bool canPlace(const Ship* newShip) const;
	/**
	 * \returns Ship which was at the Location
	 * \returns `nullptr` otherwise
	 */
	const Ship* isShipAt(const Location&) const;
	/**
	 * If Ship is hit, calls Ship::hit()
	 * \returns Ship which was hit
	 * \return nulltr otherwise
	 */
	const Ship* hit(const Location&);
	bool allShipsSunk() const;
	/**
	 * Resets `fields` on all Ships, basically
	 * unplacing them from the board, which
	 * consequently allowes them to be placed again.
	 * This is useful upon game rules violation.
	 */
	void resetLocations();
	/**
	 * \returns `true` if all ships are placed
	 * and placed according to the game rules
	 */
	bool validate() const;
	const Shot respond(const Location &loc);
	/**
	 * Replaces original ships with new ships
	 * \warning Does not check if the count and ship length
	 * is the same as before!
	 */
	void setShips(vector<Ship>);

	vector<Ship> ships;
	Player* getPlayer() const;
	const Game* getGame() const;

private:
	const Game* game;
	Player* player;
};


#endif
