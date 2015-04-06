#include "Human.h"

void HumanPlayer::setup() {
	for (auto &ship : board->ships) {
		inOut->renderBoard(board);
		inOut->askShipLoc(&ship);
	}
}

Location HumanPlayer::takeTurn() {
	return inOut->askShot(&shotsFired);
}
