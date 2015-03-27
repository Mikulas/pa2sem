#ifndef PLAYER
#define PLAYER

#include <vector>
#include "Board.h"
#include "Location.h"
#include "Ship.h"
#include "Shot.h"

using std::vector;


class Player
{
    public:
    	Shot respond(Location);
    	void setOpponent(Player*);
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;

	protected:
		Board board;
    	Shot fireAt(Location);
        vector<Shot> shotsFired;

	private:
		Player *opponent;
};


#endif
