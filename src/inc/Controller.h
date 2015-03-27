#ifndef CONTROLLER
#define CONTROLLER


#include "AIPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "InOut.h"

class Controller {
public:
	Controller(InOut* inOut);
	~Controller();
	void run();
private:
	InOut* inOut;
	Game* game;
};


#endif
