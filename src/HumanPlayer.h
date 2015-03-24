#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Player.h"

class HumanPlayer : public Player
{
    public:
		virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
