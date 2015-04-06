#include "Human.h"

vector<Ship> HumanPlayer::setup(vector<Ship> ships) {
	for (auto &ship : ships) {
		inOut->renderBoard(board);
		inOut->askShipLoc(&ship);
	}
	return ships;
}

Location HumanPlayer::takeTurn() {
	return inOut->askShot(&shotsFired);
}
