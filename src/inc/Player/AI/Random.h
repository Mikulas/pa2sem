#ifndef AIPLAYER
#define AIPLAYER

#include "AI.h"
#include "../../Random.h"


class RandomAIPlayer : public AIPlayer
{
    public:
    	RandomAIPlayer(InOut* inOut) : AIPlayer(inOut) {};
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
