#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	for (auto &ship : ships) {
		inOut->askShipLoc(&ship);
		// TODO validate all ships are placed according to rules
	}
}

void HumanPlayer::takeTurn() {
	fireAt(inOut->askShot());
}
