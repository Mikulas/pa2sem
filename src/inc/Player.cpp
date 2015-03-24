#include "Player.h"

Player::Player() {
	ships.push_back(Ship(5, "Aircraft Carrier"));
	ships.push_back(Ship(4, "Battleship"));
	ships.push_back(Ship(3, "Submarine"));
	ships.push_back(Ship(3, "Cruiser"));
	ships.push_back(Ship(2, "Destroyer"));
}

void Player::fireAt(Location location) {
	shotsFired.push_back(location);
}
