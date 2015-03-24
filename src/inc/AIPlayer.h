#ifndef AIPLAYER
#define AIPLAYER

#include "Player.h"


class AIPlayer : public Player
{
    public:
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
