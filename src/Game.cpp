#include "Game.h"

Game::Game(Player* playerA, Player* playerB) {
	this->playerA = playerA;
	this->playerB = playerB;

	this->state = State::SETUP_A;
}

void Game::gameLoop() {
	while (true) {
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
		}
		nextState();
	}
}

void Game::nextState() {
	switch (state) {
		case State::SETUP_A:
			state = State::SETUP_B;
			break;
		case State::SETUP_B:
			state = State::TURN_A;
			break;
		case State::TURN_A:
			state = State::TURN_B;
			break;
		case State::TURN_B:
			state = State::TURN_A;
			break;
	}
}
