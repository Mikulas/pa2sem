#ifndef RANDOMMEMAIPLAYER
#define RANDOMMEMAIPLAYER

#include <algorithm>
#include <random>
#include "../Player.h"
#include "../../Random.h"

using std::default_random_engine;
using std::shuffle;


class RandomWithMemoryAIPlayer : public Player
{
    public:
    	RandomWithMemoryAIPlayer(InOut* inOut) : Player(inOut) {
    		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
    			for (unsigned int y = 0; y < BOARD_SIZE; y++) {
    				shootAt.push_back(new Location(x, y));
    			}
    		}
    		auto engine = default_random_engine{};
			shuffle(std::begin(shootAt), std::end(shootAt), engine);
    	};
		virtual void setup() override;
    	virtual void takeTurn() override;

    private:
    	vector<Location*> shootAt;
};


#endif
