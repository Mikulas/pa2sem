#include "Player.h"

void Player::fireAt(Location location) {
	shotsFired.push_back(location);
}
