#include "Controller.h"

Controller::Controller(IRenderer* renderer) {
	this->renderer = renderer;
	this->game = new Game();
}

Controller::~Controller() {
	delete this->renderer;
	delete this->game;
}

void Controller::run() {
}
