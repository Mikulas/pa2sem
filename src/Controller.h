#include "Game.h"
#include "IRenderer.h"
#include "HumanPlayer.h"

class Controller {
public:
	Controller(IRenderer* renderer);
	~Controller();
	void run();
private:
	IRenderer* renderer;
	Game* game;
};
