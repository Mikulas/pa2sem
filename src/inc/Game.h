#ifndef GAME_H
#define GAME_H

class Game;

#include "Board.h"
#include "InOut.h"
#include "Player/Player.h"

/**
 * Controls game flow as simple finite state machine.
 *
 * Delegates validation of many game rules to Board
 */
class Game {
public:
	Game(InOut* inOut, Player* playerA, Player* playerB);
	~Game();
	/**
	 * Calls Player::setup or Player::takeTurn based on State
	 * until either of the players wins by sinking all opponents ships.
	 */
	void gameLoop();

private:
	enum class State : char {INIT, SETUP_A, SETUP_B, TURN_A, TURN_B, OVER};

	unsigned int turn; /**< One turn means all players fire a shot */
	State state;

	InOut* inOut;
	Board* boardA;
	Board* boardB;

	void gameOver(Player* player);

	void setupBoard(Board*);
	void playTurn(Board* active, Board* opponent);

	void nextState();
};


#endif
