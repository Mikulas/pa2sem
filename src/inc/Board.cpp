#include "Board.h"

Board::Board() {
	ships.push_back(Ship(5, "Aircraft Carrier"));
	ships.push_back(Ship(4, "Battleship"));
	ships.push_back(Ship(3, "Submarine"));
	ships.push_back(Ship(3, "Cruiser"));
	ships.push_back(Ship(2, "Destroyer"));
}

const Ship* Board::isShipAt(const Location loc) const {
	for (auto &ship : ships) {
		if (ship.overlaps(loc)) {
			return &ship;
		}
	}
	return nullptr;
}

const Ship* Board::hit(const Location loc) {
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
		if (ship.overlaps(newShip)) {
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
