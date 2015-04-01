#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
#include "../Board.h"
#include "../Game.h"
#include "../InOut.h"
#include "../Location.h"
#include "../Ship.h"
#include "../Shot.h"

using std::vector;


/**
 * \interface Player
 * \pure
 */
class Player
{
    public:
        Player() {}
        void setOpponent(Player*);
        void setGame(Game*);
    	virtual const Shot respond(const Location) = 0;
        virtual void setup() = 0;
    	virtual void takeTurn() = 0;
        virtual bool allShipsSunk() const = 0;

	protected:
		Board board;
    	vector<Shot> shotsFired;
		Player *opponent;
        Game *game;
};

#endif
