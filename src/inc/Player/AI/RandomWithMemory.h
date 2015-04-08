#ifndef RANDOMMEMAIPLAYER
#define RANDOMMEMAIPLAYER

#include <algorithm>
#include <random>
#include "AI.h"
#include "../../Random.h"

using std::default_random_engine;
using std::shuffle;


/**
 * Fires at random locations, but never
 * repeats previous target.
 *
 * Takes about 95 turns on average to sunk all ships.
 * Upper bound is board size: 100 turns for 10x10 board.
 */
class RandomWithMemoryAIPlayer : public AIPlayer {
public:
	RandomWithMemoryAIPlayer() {
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			for (unsigned int y = 0; y < BOARD_SIZE; y++) {
				shootAt.push_back(new Location(x, y));
			}
		}
		auto engine = default_random_engine{};
		shuffle(std::begin(shootAt), std::end(shootAt), engine);
	};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;

private:
	vector<const Location*> shootAt;
};


#endif
