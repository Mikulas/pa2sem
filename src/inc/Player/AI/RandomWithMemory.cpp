#include "RandomWithMemory.h"

void RandomWithMemoryAIPlayer::setup() {
	placeShipsRandomly();
}

Location RandomWithMemoryAIPlayer::takeTurn() {
	Location loc = *shootAt.back();
	delete shootAt.back();
	shootAt.pop_back();

	return loc;
}
