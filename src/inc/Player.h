#ifndef PLAYER
#define PLAYER

#include <vector>
#include "Location.h"
#include "Ship.h"

using std::vector;


class Player
{
    public:
    	Player();
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;
	
	protected:
    	void fireAt(Location);
    	vector<Ship> ships;

	private:
		vector<Location> shotsFired;
};


#endif
