#include "Random.h"

void RandomAIPlayer::setup() {
	placeShipsRandomly();
}

Location RandomAIPlayer::takeTurn() {
	return Random::location();
}
