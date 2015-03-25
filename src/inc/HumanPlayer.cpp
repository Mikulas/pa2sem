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
	fireAt(inOut->askShot());
	
	// TODO what now???
	// ALSO track state in shotsFired
}
