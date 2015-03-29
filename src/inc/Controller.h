#ifndef CONTROLLER
#define CONTROLLER


#include "Game.h"
#include "InOut.h"
#include "Player/AI/Random.h"
#include "Player/Human.h"

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
