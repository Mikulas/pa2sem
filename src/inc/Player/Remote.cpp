#include "Remote.h"

void RemotePlayer::setup() {
	server->invoke("setup");
}

void RemotePlayer::takeTurn() {
	server->invoke("takeTurn");
}
