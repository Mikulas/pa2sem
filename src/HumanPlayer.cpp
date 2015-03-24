#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(InOut* inOut) {
	this->inOut = inOut;
}

void HumanPlayer::setup() {
	inOut->askShipLoc(5, "Destroyer");
}

void HumanPlayer::takeTurn() {

}
