#ifndef PLAYER
#define PLAYER

#include <vector>
#include "Location.h"
#include "Ship.h"

using std::vector;


class Player
{
    public:
	private:
		vector<Location> shotsFired;
		vector<Ship> ships;
};


#endif
