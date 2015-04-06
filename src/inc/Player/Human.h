#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Player.h"


class HumanPlayer : public Player
{
    public:
    	HumanPlayer(InOut* inOut) : Player(inOut) {};
    	virtual vector<Ship> setup(vector<Ship>) override;
    	virtual Location takeTurn() override;
};


#endif
