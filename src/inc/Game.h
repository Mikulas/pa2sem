#ifndef GAME
#define GAME

class Game;

#include "InOut.h"
#include "Player.h"


enum class State : char {INIT, SETUP_A, SETUP_B, TURN_A, TURN_B, OVER};

class Game {
public:
	Game(InOut* inOut, Player* playerA, Player* playerB);
	void gameLoop();
	void gameOver(Player* player);

private:
	State state;

	InOut* inOut;
	Player* playerA;
	Player* playerB;

	void nextState();
};


#endif
