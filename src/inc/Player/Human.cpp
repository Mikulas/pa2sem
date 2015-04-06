#include "Human.h"

void HumanPlayer::setup() {
	for (auto &ship : board->ships) {
		inOut->askShipLoc(&ship);
	}
}

void HumanPlayer::takeTurn() {
	const Shot shot = fireAt(inOut->askShot(&shotsFired));
	inOut->renderShotResult(shot);
}
