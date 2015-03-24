#ifndef GAME
#define GAME

#include "Player.h"


enum class State : char {SETUP_A, SETUP_B, TURN_A, TURN_B};

class Game {
public:
	Game(Player* playerA, Player* playerB);
	void gameLoop();

private:
	State state;

	Player* playerA;
	Player* playerB;

	void nextState();
};


#endif
