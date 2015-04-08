#include "Board.h"

Board::~Board() {
	delete player;
}

Board::Board(const Game* game, Player* player) : game(game), player(player) {
	ships.push_back(Ship(5, "Aircraft Carrier"));
	ships.push_back(Ship(4, "Battleship"));
	ships.push_back(Ship(3, "Submarine"));
	ships.push_back(Ship(3, "Cruiser"));
	ships.push_back(Ship(2, "Destroyer"));
}

const Ship* Board::isShipAt(const Location &loc) const {
	for (auto &ship : ships) {
		if (ship.overlaps(loc)) {
			return &ship;
		}
	}
	return nullptr;
}

const Ship* Board::hit(const Location &loc) {
	for (auto &ship : ships) {
		if (ship.hit(loc)) {
			return &ship;
		}
	}
	return nullptr;
}

bool Board::canPlace(const Ship* newShip) const {
	if (!newShip->isPlaced()) {
		return false;
	}

	for (auto &ship : ships) {
		if (&ship != newShip && ship.overlaps(newShip)) {
			return false;
		}
	}
	return true;
}

bool Board::allShipsSunk() const {
	for (auto &ship : ships) {
		if (!ship.isSunk()) {
			return false;
		}
	}
	return true;
}

const Game* Board::getGame() const {
	return game;
}

Player* Board::getPlayer() const {
	return player;
}

void Board::resetLocations() {
	for (auto &ship : ships) {
		ship.unplace();
	}
}

bool Board::validate() const {
	for (auto it = ships.begin(); it != ships.end(); ++it) {
		if (!it->isPlaced()) {
			return false;
		}
		for (auto it2 = it + 1; it2 != ships.end(); ++it2) {
			if (it->overlaps(&(*it2))) {
				return false;
			}
		}
	}
	return true;
}

const Shot Board::respond(const Location &loc) {
	Shot shot(loc);
	const Ship* ship = hit(loc);
	if (!ship) {
		shot.response = Shot::Response::MISS;

	} else if (ship->isSunk()) {
		shot.response = Shot::Response::SUNK;

	} else {
		shot.response = Shot::Response::HIT;
	}

	return shot;
}

void Board::setShips(vector<Ship> newShips) {
	ships.clear();
	for (auto &ship : newShips) {
		ships.push_back(ship);
	}
}
