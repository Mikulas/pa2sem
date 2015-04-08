#ifndef PLAYER_HUMAN_H
#define PLAYER_HUMAN_H

#include "Local.h"


/**
 * Asks user for input.
 * All input and output must be done through InOut.
 */
class HumanPlayer : public LocalPlayer {
public:
	HumanPlayer(InOut* inOut) : inOut(inOut) {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;

private:
    InOut* inOut;
};


#endif
