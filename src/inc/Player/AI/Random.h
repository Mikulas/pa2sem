#ifndef AIPLAYER
#define AIPLAYER

#include "AI.h"
#include "../../Random.h"


class RandomAIPlayer : public AIPlayer
{
    public:
    	RandomAIPlayer() {};
		virtual vector<Ship> setup(vector<Ship>) override;
    	virtual Location takeTurn() override;
};


#endif
