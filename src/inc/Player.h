#ifndef PLAYER
#define PLAYER

#include <vector>
#include "Board.h"
#include "Location.h"
#include "Ship.h"

using std::vector;


class Player
{
    public:
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;

	protected:
		Board board;
    	void fireAt(Location);

	private:
		vector<Location> shotsFired;
};


#endif
