#include "Remote.h"

void RemotePlayer::setup() {
	server->invoke("setup");
	// TODO
}

void RemotePlayer::takeTurn() {
	server->invoke("takeTurn");
	// TODO
}

const Shot RemotePlayer::respond(const Location) {
	server->invoke("respond");
	// TODO
}

bool RemotePlayer::allShipsSunk() const {
	server->invoke("allShipsSunk");
	// TODO
}
