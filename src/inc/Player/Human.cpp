#include "Human.h"

vector<Ship> HumanPlayer::setup(vector<Ship> ships) {
	while (true) {
		if (forceRandomShips) {
			return placeShipsRandomly(ships);
		}

		string answer = inOut->ask("Would you like the ships to be placed randomly? [Y/n]: ");
		if (answer[0] == 'y' || answer[0] == 'Y') {
			forceRandomShips = true;
			return placeShipsRandomly(ships);

		} else if (answer[0] == 'n' || answer[0] == 'N') {
			break;
		}
	}

	for (auto &ship : ships) {
		inOut->renderShips(ships);
		inOut->askShipLoc(&ship);
	}
	return ships;
}

Location HumanPlayer::takeTurn() {
	return inOut->askShot(&shotsFired);
}
