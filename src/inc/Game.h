#ifndef GAME
#define GAME

class Game;

#include "Board.h"
#include "InOut.h"
#include "Player/Player.h"


enum class State : char {INIT, SETUP_A, SETUP_B, TURN_A, TURN_B, OVER};

class Game {
public:
	Game(InOut* inOut, Player* playerA, Player* playerB);
	~Game();
	void gameLoop();
	void gameOver(Player* player);

private:
	unsigned int turn; /**< One turn means all players fire a shot */
	State state;

	InOut* inOut;
	Board* boardA;
	Board* boardB;

	void nextState();
};


#endif
