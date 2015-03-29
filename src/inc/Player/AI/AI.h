#ifndef AIBASEPLAYER
#define AIBASEPLAYER

#include "../Player.h"
#include "../../Random.h"


/**
 * \pure
 */
class AIPlayer : public Player
{
	public:
		AIPlayer(InOut* inOut) : Player(inOut) {};
    protected:
    	void placeShipsRandomly();
};


#endif
