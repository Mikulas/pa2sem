#include "Game.h"

Game::Game(InOut* inOut, Player* playerA, Player* playerB) {
	this->inOut = inOut;

	this->boardA = new Board(this, playerA);
	this->boardB = new Board(this, playerB);
	this->boardA->setOpponent(this->boardB); // TODO remove
	this->boardB->setOpponent(this->boardA);

	this->state = State::INIT;
}

Game::~Game() {
	delete boardA;
	delete boardB;
}

void Game::setupBoard(Board* board) {
	while (true) {
		auto ships = board->getPlayer()->setup(board->ships);
		board->setShips(ships);
		if (board->validate()) {
			break;
		}
		board->resetLocations();
	};

	// TODO remove, debug
	inOut->renderShips(board->ships);
}

void Game::playTurn(Board* active, Board* opponent) {
	Location loc = active->getPlayer()->takeTurn();
	const Shot shot = opponent->respond(loc);
	active->getPlayer()->saveShot(shot);
	inOut->renderShotResult(shot);

	if (opponent->allShipsSunk()) {
		gameOver(active->getPlayer());
	}
}

void Game::gameLoop() {
	while (true) {
		switch (state) {
			case State::SETUP_A:
				setupBoard(boardA);
				break;

			case State::SETUP_B:
				setupBoard(boardB);
				break;

			case State::TURN_A:
				playTurn(boardA, boardB);
				break;

			case State::TURN_B:
				playTurn(boardB, boardA);
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
