#include "Controller.h"

Controller::Controller(IRenderer* renderer) {
	this->renderer = renderer;
}

Controller::~Controller() {
	delete this->renderer;
	delete this->game;
}

void Controller::run() {
	// string mode;
	// do {
	// 	mode = renderer->ask("Select game mode: play against AI,\nhot seat on this pc, or play on network. [ai/pc/net]: ");
	// } while (mode != "ai" && mode != "player");

	// if (mode == "player") {
		this->game = new Game(new HumanPlayer, new HumanPlayer);
		this->game->gameLoop();
	// }
}
