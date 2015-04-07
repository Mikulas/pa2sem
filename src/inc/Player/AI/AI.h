#ifndef AIBASEPLAYER
#define AIBASEPLAYER

#include "../Local.h"
#include "../../Random.h"


/**
 * \pure
 */
class AIPlayer : public LocalPlayer
{
    protected:
    	vector<Ship> placeShipsRandomly(vector<Ship>);
};


#endif
