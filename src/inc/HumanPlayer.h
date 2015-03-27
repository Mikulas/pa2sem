#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Player.h"


class HumanPlayer : public Player
{
    public:
    	HumanPlayer(InOut* inOut) : Player(inOut) {};
    	virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
