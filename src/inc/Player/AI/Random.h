#ifndef AIPLAYER
#define AIPLAYER

#include "AI.h"
#include "../../Random.h"


/**
 * Fires at random locations, with possible
 * duplicated locations.
 *
 * Takes roughly 300 turns on average to sunk all ships,
 * but is not bound and might run forever.
 */
class RandomAIPlayer : public AIPlayer {
public:
	RandomAIPlayer() {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;
};


#endif
