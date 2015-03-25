#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	for (auto &ship : board.ships) {
		inOut->askShipLoc(&ship, &board);
	}
}

void HumanPlayer::takeTurn() {
	fireAt(inOut->askShot());
}
