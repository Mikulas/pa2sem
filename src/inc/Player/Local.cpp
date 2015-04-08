#include "Local.h"

void LocalPlayer::saveShot(Shot shot) {
	shotsFired.push_back(shot);
}

vector<Ship> LocalPlayer::placeShipsRandomly(vector<Ship> ships) {
	for (auto &ship : ships) {
		while (true) {
			Location start = Random::location();
			Location end = Random::location(start, ship.length);

			ship.setStartEnd(start, end);

			for (auto &other : ships) {
				if (&ship != &other && ship.overlaps(&other)) {
					continue;
				}
			}
			break;
		}
	}

	return ships;
}
