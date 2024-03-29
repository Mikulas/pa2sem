#ifndef PLAYER_AI_RANDOM_H
#define PLAYER_AI_RANDOM_H

#include "AI.h"
#include "../../Random.h"


/**
 * Fires at random locations, with possible
 * duplicated locations.
 *
 * Takes 220 turns on average to sunk all ships,
 * but is not bound and might run forever.
 *
 * \ingroup Player
 */
class RandomAIPlayer : public AIPlayer {
public:
	RandomAIPlayer() {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;
};


#endif
