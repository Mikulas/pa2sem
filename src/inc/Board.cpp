#include "Board.h"

Board::Board() {
	ships.push_back(Ship(5, "Aircraft Carrier"));
	ships.push_back(Ship(4, "Battleship"));
	ships.push_back(Ship(3, "Submarine"));
	ships.push_back(Ship(3, "Cruiser"));
	ships.push_back(Ship(2, "Destroyer"));
}

bool Board::canPlace(Ship* newShip) {
	for (auto &ship : ships) {
		if (ship.overlaps(newShip)) {
			return false;
		}
	}
	return true;
}
