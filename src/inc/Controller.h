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


/**
 * Asks user for game configuration, for example
 * what players should be in the game.
 */
class Controller {
public:
	Controller(InOut* inOut);
	~Controller();
	/**
	 * Calls Game::gameLoop(), which blocks until either
	 * one of the players win.
	 * \throws ServerException (only in networked game)
	 */
	void run();
private:
	InOut* inOut;
	Game* game;
	Server* server;
};


#endif
