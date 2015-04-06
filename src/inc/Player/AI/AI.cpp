#include "AI.h"

vector<Ship> AIPlayer::placeShipsRandomly(vector<Ship> ships) {
	for (auto &ship : ships) {
		while (true) {
			Location start = Random::location();
			Location end = Random::location(start, ship.length);
			ship.setStartEnd(start, end);


			break;
			// TODO reimpl here
			//if (board->canPlace(&ship)) {
			//	break;
			//}
		}
	}

	return ships;
}
