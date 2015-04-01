#include "Local.h"

const Shot LocalPlayer::respond(const Location loc) {
	Shot shot(loc);
	const Ship* ship = this->board.hit(loc);
	if (!ship) {
		shot.response = Response::MISS;

	} else if (ship->isSunk()) {
		shot.response = Response::SUNK;

	} else {
		shot.response = Response::HIT;
	}

	return shot;
}

const Shot LocalPlayer::fireAt(const Location location) {
	const Shot shot = opponent->respond(location);
	shotsFired.push_back(shot);
	if (shot.response == Response::SUNK) {
		if (opponent->allShipsSunk()) {
			game->gameOver(this);
		}
	}
	return shot;
}

bool LocalPlayer::allShipsSunk() const {
	return board.allShipsSunk();
}
