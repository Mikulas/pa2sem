#ifndef GAME
#define GAME

#include "InOut.h"
#include "Player.h"


enum class State : char {INIT, SETUP_A, SETUP_B, TURN_A, TURN_B};

class Game {
public:
	Game(InOut* inOut, Player* playerA, Player* playerB);
	void gameLoop();

private:
	State state;

	InOut* inOut;
	Player* playerA;
	Player* playerB;

	void nextState();
};


#endif
