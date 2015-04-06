#ifndef CONTROLLER
#define CONTROLLER


#include "Game.h"
#include "InOut.h"
#include "Net/Server.h"
#include "Player/AI/Random.h"
#include "Player/AI/RandomWithMemory.h"
#include "Player/Human.h"
#include "Player/Remote.h"


class Controller {
public:
	Controller(InOut* inOut);
	~Controller();
	void run();
private:
	InOut* inOut;
	Game* game;
	Server* server;
};


#endif
