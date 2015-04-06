#include "Player.h"

void Player::setBoard(Board* board) {
	this->board = board;
}

void Player::saveShot(Shot shot) {
	shotsFired.push_back(shot);
}
