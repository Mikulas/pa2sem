#ifndef AIBASEPLAYER
#define AIBASEPLAYER

#include "../Player.h"
#include "../../Random.h"


class AIPlayer : public Player
{
	public:
		AIPlayer(InOut* inOut) : Player(inOut) {};
    protected:
    	void placeShipsRandomly();
};


#endif
