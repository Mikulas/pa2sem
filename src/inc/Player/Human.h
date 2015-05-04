#ifndef PLAYER_HUMAN_H
#define PLAYER_HUMAN_H

#include "Local.h"


/**
 * Asks user for input.
 * All input and output must be done through InOut.
 *
 * \ingroup Player
 */
class HumanPlayer : public LocalPlayer {
public:
	HumanPlayer(InOut* inOut) : inOut(inOut) {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;

private:
	bool forceRandomShips = false;
    InOut* inOut;
};


#endif
