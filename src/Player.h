#ifndef PLAYER
#define PLAYER

#include <vector>
#include "Location.h"
#include "Ship.h"

using std::vector;


class Player
{
    public:
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;
	private:
		vector<Location> shotsFired;
		vector<Ship> ships;
};


#endif
