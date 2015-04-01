#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Local.h"


class HumanPlayer : public LocalPlayer
{
    public:
    	HumanPlayer(InOut* inOut) : LocalPlayer(inOut) {};
    	virtual void setup() override;
    	virtual void takeTurn() override;
};


#endif
