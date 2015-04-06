#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
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
        virtual vector<Ship> setup(vector<Ship>) = 0;
    	virtual Location takeTurn() = 0;
        void saveShot(Shot);

	protected:
    	vector<Shot> shotsFired;
        InOut* inOut;
};

#endif
