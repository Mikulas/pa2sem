#include "Random.h"

vector<Ship> RandomAIPlayer::setup(vector<Ship> ships) {
	return placeShipsRandomly(ships);
}

Location RandomAIPlayer::takeTurn() {
	return Random::location();
}
