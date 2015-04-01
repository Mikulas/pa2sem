#include "Game.h"

Game::Game(InOut* inOut, Player* playerA, Player* playerB) {
	this->inOut = inOut;

	playerA->setGame(this);
	playerB->setGame(this);
	this->boardA = new Board(playerA);
	this->boardB = new Board(playerB);

	this->state = State::INIT;
}

Game::~Game() {
	delete boardA;
	delete boardB;
}

void Game::gameLoop() {
	while (true) {
		switch (state) {
			case State::SETUP_A:
				//boardA->ships
				boardA->getPlayer()->setup();
				break;
			case State::SETUP_B:
				//boardB->ships
				boardB->getPlayer()->setup();
				break;
			case State::TURN_A:
				boardA->getPlayer()->takeTurn();
				break;
			case State::TURN_B:
				boardB->getPlayer()->takeTurn();
				break;
			case State::OVER:
				return;
			default:
				break;
		}

		nextState();
	}
}

void Game::nextState() {
	switch (state) {
		case State::OVER:
			break;
		case State::SETUP_A:
			state = State::SETUP_B;
			inOut->announce("Player B setup phase");
			break;
		case State::SETUP_B:
		case State::TURN_B:
			state = State::TURN_A;
			turn++;
			inOut->announceTurn("Player A", turn);
			break;
		case State::TURN_A:
			state = State::TURN_B;
			inOut->announceTurn("Player B", turn);
			break;
		case State::INIT:
		default:
			state = State::SETUP_A;
			inOut->announce("Player A setup phase");
	}
}

void Game::gameOver(Player* player) {
	if (this->boardA->getPlayer() == player) {
		inOut->gameOver("Player A");
	} else {
		inOut->gameOver("Player B");
	}

	state = State::OVER;
}
