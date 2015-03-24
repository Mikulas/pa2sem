#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "InOut.h"
#include "Player.h"


class HumanPlayer : public Player
{
    public:
    	HumanPlayer(InOut* inOut);
		virtual void setup() override;
    	virtual void takeTurn() override;
    private:
    	InOut* inOut;
};


#endif
