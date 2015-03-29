#ifndef AIPLAYER
#define AIPLAYER

#include "../Player.h"
#include "../../Random.h"


class RandomAIPlayer : public Player
{
    public:
    	RandomAIPlayer(InOut* inOut) : Player(inOut) {};
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
