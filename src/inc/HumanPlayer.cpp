#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	for (auto &ship : board.ships) {
		inOut->askShipLoc(&ship, &board);
		inOut->renderBoard(&board);
	}
}

void HumanPlayer::takeTurn() {
	Shot shot = fireAt(inOut->askShot());
	inOut->renderShotResult(shot);
}
