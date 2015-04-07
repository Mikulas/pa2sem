#ifndef HUMANPLAYER
#define HUMANPLAYER

#include "Local.h"


class HumanPlayer : public LocalPlayer
{
public:
	HumanPlayer(InOut* inOut) : inOut(inOut) {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;

private:
    InOut* inOut;
};


#endif
