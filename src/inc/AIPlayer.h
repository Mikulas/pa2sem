#ifndef AIPLAYER
#define AIPLAYER

#include "Player.h"
#include "Random.h"


class AIPlayer : public Player
{
    public:
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
