#include "Game.h"

Game::Game(InOut* inOut, Player* playerA, Player* playerB) {
	this->inOut = inOut;
	this->playerA = playerA;
	this->playerB = playerB;

	this->state = State::INIT;
}

void Game::gameLoop() {
	while (true) {
		nextState();

		switch (state) {
			case State::SETUP_A:
				playerA->setup();
				break;
			case State::SETUP_B:
				playerB->setup();
				break;
			case State::TURN_A:
				playerA->takeTurn();
				break;
			case State::TURN_B:
				playerB->takeTurn();
				break;
			default:
				break;
		}
	}
}

void Game::nextState() {
	switch (state) {
		case State::SETUP_A:
			state = State::SETUP_B;
			inOut->announce("Player B setup phase");
			break;
		case State::SETUP_B:
		case State::TURN_B:
			state = State::TURN_A;
			inOut->announce("Player A turn");
			break;
		case State::TURN_A:
			state = State::TURN_B;
			inOut->announce("Player B turn");
			break;
		case State::INIT:
		default:
			state = State::SETUP_A;
			inOut->announce("Player A setup phase");
	}
}
