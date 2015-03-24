#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	for (auto &ship : ships) {
		inOut->askShipLoc(&ship);
	}
}

void HumanPlayer::takeTurn() {
	fireAt(inOut->askShot());
}
