#include "Remote.h"

void RemotePlayer::setup() {
	server->invoke("setup");
	// TODO
}

void RemotePlayer::takeTurn() {
	server->invoke("takeTurn");
	// TODO
}

const Shot RemotePlayer::respond(const Location location) {
	server->invoke("respond", location);
	// TODO
}

bool RemotePlayer::allShipsSunk() const {
	server->invoke("allShipsSunk");
	// TODO
}
