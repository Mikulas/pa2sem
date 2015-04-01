#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
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
        Player(InOut* inOut) : inOut(inOut) {};
    	const Shot respond(const Location);
        void setGame(Game*);
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;

	protected:
    	const Shot fireAt(const Location);
        vector<Shot> shotsFired;
        InOut* inOut;

	private:
		Player *opponent;
        Game *game;
};

#endif
