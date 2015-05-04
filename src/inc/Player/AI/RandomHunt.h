#ifndef PLAYER_AI_RANDOMHUNT_H
#define PLAYER_AI_RANDOMHUNT_H

#include <algorithm>
#include <random>
#include "../../Random.h"
#include "AI.h"

using std::default_random_engine;
using std::shuffle;

/**
 * In search mode fires at random locations without
 * repeating same locations. On a successfull hit,
 * switches to hunt mode and fires at all nearby
 * fields that were not fired at before.
 *
 * Takes 57 turns on average to sunk all ships.
 * Upper bound is board size: 100 turns for 10x10 board.
 *
 * \ingroup Player
 */
class RandomHuntAIPlayer : public AIPlayer {
public:
	RandomHuntAIPlayer();
	~RandomHuntAIPlayer() {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;

private:
	void addHunted(unsigned int x, unsigned int y);
	void addHunted(Location &loc);

	vector<const Location*> shootAt;
	set<const Location*> hunted;
};


#endif
