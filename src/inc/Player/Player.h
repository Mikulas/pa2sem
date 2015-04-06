#ifndef PLAYER
#define PLAYER

class Player;

#include <vector>
#include "../Board.h"
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
        void setBoard(Board*);
    	virtual void setup() = 0;
    	virtual void takeTurn() = 0;

	protected:
    	const Shot fireAt(const Location);
        vector<Shot> shotsFired;
        InOut* inOut;
        Board *board;
};

#endif
