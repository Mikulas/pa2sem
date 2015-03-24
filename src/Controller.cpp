#include "Controller.h"

Controller::Controller(InOut* inOut) {
	this->inOut = inOut;
}

Controller::~Controller() {
	delete this->inOut;
	delete this->game;
}

void Controller::run() {
	// string mode;
	// do {
	// 	mode = inOut->ask("Select game mode: play against AI,\nhot seat on this pc, or play on network. [ai/pc/net]: ");
	// } while (mode != "ai" && mode != "player");

	// if (mode == "player") {
		this->game = new Game(new HumanPlayer(inOut), new HumanPlayer(inOut));
		this->game->gameLoop();
	// }
}
