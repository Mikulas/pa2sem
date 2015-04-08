#include "RandomWithMemory.h"

RandomWithMemoryAIPlayer::~RandomWithMemoryAIPlayer() {
	for (auto &loc : shootAt) {
		delete loc;
	}
}

vector<Ship> RandomWithMemoryAIPlayer::setup(vector<Ship> ships) {
	return placeShipsRandomly(ships);
}

Location RandomWithMemoryAIPlayer::takeTurn() {
	Location loc = *shootAt.back();
	delete shootAt.back();
	shootAt.pop_back();

	return loc;
}
