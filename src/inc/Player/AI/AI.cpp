#include "AI.h"

void AIPlayer::placeShipsRandomly() {
	for (auto &ship : board->ships) {
		while (true) {
			Location start = Random::location();
			Location end = Random::location(start, ship.length);
			ship.setStartEnd(start, end);
			if (board->canPlace(&ship)) {
				break;
			}
		}
	}
}
