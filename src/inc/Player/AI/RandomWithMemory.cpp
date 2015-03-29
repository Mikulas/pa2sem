#include "RandomWithMemory.h"

void RandomWithMemoryAIPlayer::setup() {
	placeShipsRandomly();
}

void RandomWithMemoryAIPlayer::takeTurn() {
	Shot shot = fireAt(*shootAt.back());
	delete shootAt.back();
	shootAt.pop_back();
	inOut->renderShotResult(shot);
}
