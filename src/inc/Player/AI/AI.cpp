#include "AI.h"

void AIPlayer::placeShipsRandomly() {
	for (auto &ship : board.ships) {
		do {
			Ship newShip = ship;
			Location start = Random::location();
			Location end = Random::location(start, ship.length);
			if (!newShip.setStartEnd(start, end)) {
				continue;
			}
			if (!board.canPlace(&newShip)) {
				continue;
			}

			// ok set coords for original ship
			ship.setStartEnd(start, end);
			break;
		} while (true);
	}
}