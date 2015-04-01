#include "Remote.h"

void RemotePlayer::setup() {
	server->invoke("setup");
}

void RemotePlayer::takeTurn() {
	server->invoke("takeTurn");
}

const Shot RemotePlayer::respond(const Location) {
	// TODO
}

bool RemotePlayer::allShipsSunk() const {
	// TODO
}
