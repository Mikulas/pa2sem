#include "RandomWithMemory.h"

void RandomWithMemoryAIPlayer::setup() {
	// TODO same as Random, refactor
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

void RandomWithMemoryAIPlayer::takeTurn() {
	Shot shot = fireAt(*shootAt.back());
	delete shootAt.back();
	shootAt.pop_back();
	inOut->renderShotResult(shot);
}
