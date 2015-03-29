#include "Player.h"

void Player::setOpponent(Player* opponent) {
	this->opponent = opponent;
}

void Player::setGame(Game* game) {
	this->game = game;
}

Shot Player::respond(Location loc) {
	Shot shot(loc);
	Ship* ship = this->board.hit(loc);
	if (!ship) {
		shot.response = Response::MISS;

	} else if (ship->isSunk()) {
		shot.response = Response::SUNK;

	} else {
		shot.response = Response::HIT;
	}

	return shot;
}

Shot Player::fireAt(Location location) {
	Shot shot = opponent->respond(location);
	shotsFired.push_back(shot);
	if (shot.response == Response::SUNK) {
		if (opponent->board.allShipsSunk()) {
			game->gameOver(this);
		}
	}
	return shot;
}