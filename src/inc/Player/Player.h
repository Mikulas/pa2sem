#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
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
    virtual vector<Ship> setup(vector<Ship>) = 0;
	virtual Location takeTurn() = 0;
	virtual void saveShot(Shot) = 0;
};

#endif
