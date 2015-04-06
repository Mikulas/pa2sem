#include "Player.h"

void Player::setBoard(Board* board) {
	this->board = board;
}

const Shot Player::fireAt(const Location location) {
	const Shot shot = board->opponent->respond(location);
	shotsFired.push_back(shot);
	return shot;
}
