#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Local.h"


class HumanPlayer : public LocalPlayer
{
    public:
    	HumanPlayer(InOut* inOut) : LocalPlayer(inOut) {};
    	virtual vector<Ship> setup(vector<Ship>) override;
    	virtual Location takeTurn() override;
};


#endif
