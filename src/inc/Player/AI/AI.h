#ifndef AIBASEPLAYER
#define AIBASEPLAYER

#include "../Local.h"
#include "../../Random.h"


/**
 * \pure
 */
class AIPlayer : public LocalPlayer
{
	public:
		AIPlayer(InOut* inOut) : LocalPlayer(inOut) {};
    protected:
    	void placeShipsRandomly();
};


#endif
