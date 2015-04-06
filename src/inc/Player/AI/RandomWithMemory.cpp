#include "RandomWithMemory.h"

vector<Ship> RandomWithMemoryAIPlayer::setup(vector<Ship> ships) {
	return placeShipsRandomly(ships);
}

Location RandomWithMemoryAIPlayer::takeTurn() {
	Location loc = *shootAt.back();
	delete shootAt.back();
	shootAt.pop_back();

	return loc;
}
