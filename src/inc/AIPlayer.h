#ifndef AIPLAYER
#define AIPLAYER

#include "Player.h"
#include "Random.h"


class AIPlayer : public Player
{
    public:
    	AIPlayer(InOut* inOut) : Player(inOut) {};
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
