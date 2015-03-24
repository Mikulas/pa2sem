#include "Game.h"
#include "InOut.h"
#include "HumanPlayer.h"

class Controller {
public:
	Controller(InOut* inOut);
	~Controller();
	void run();
private:
	InOut* inOut;
	Game* game;
};
