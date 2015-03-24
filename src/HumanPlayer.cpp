#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	// todo iterate over ships and ask for loc
}

void HumanPlayer::takeTurn() {
	fireAt(inOut->askShot());
}
