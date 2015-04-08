#ifndef CONTROLLER
#define CONTROLLER


#include <vector>
#include "Game.h"
#include "InOut.h"
#include "InOutBroadcast.h"
#include "Net/Server.h"
#include "Player/Factory.h"
#include "Player/Remote.h"

using std::vector;


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
