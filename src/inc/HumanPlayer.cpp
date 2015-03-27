#include "HumanPlayer.h"

void HumanPlayer::setup() {
	inOut->renderBoard(&board);
	for (auto &ship : board.ships) {
		inOut->askShipLoc(&ship, &board);
		inOut->renderBoard(&board);
	}
}

void HumanPlayer::takeTurn() {
	Shot shot = fireAt(inOut->askShot(shotsFired));
	inOut->renderShotResult(shot);
}
