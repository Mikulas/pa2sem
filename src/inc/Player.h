#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
#include "Board.h"
#include "Game.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"

using std::vector;


class Player
{
    public:
    	Shot respond(Location);
    	void setOpponent(Player*);
        void setGame(Game*);
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;

	protected:
		Board board;
    	Shot fireAt(Location);
        vector<Shot> shotsFired;

	private:
		Player *opponent;
        Game *game;
};


#endif
