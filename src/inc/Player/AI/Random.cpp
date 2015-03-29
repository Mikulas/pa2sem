#include "Random.h"

void RandomAIPlayer::setup() {
	placeShipsRandomly();
}

void RandomAIPlayer::takeTurn() {
	Shot shot = fireAt(Random::location());
	inOut->renderShotResult(shot);
}
