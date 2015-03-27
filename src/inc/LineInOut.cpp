#include "LineInOut.h"

Location LineInOut::readLocation() {
	string answer;

	int res = -1;
	unsigned int x, y;
	do {
		if (res != -1) {
			cout << "enter 'x y' ranged <0, 9>: ";
			cout.flush();
		}

		getline(cin, answer);

		res = sscanf(answer.c_str(), "%d %d", &x, &y);
		if (res == 2) {
			try {
				return Location(x, y);
			} catch (exception* e) {
				continue;
			}
			break;
		}

	} while (true);
}

string LineInOut::ask(string question) {
	string answer;

	cout << question << " >> ";
	getline(cin, answer);

	return answer;
}

void LineInOut::announce(string msg) {
	cout << C::underline << msg << C::reset << endl;
}

string LineInOut::getCharForShip(Ship* ship) {
	if (!symbolMap.count(ship)) {
		string s[] = {
			C::cyan + "Ⓐ",
			C::green + "Ⓑ",
			C::yellow + "Ⓒ",
			C::blue + "Ⓓ",
			C::magenta + "Ⓔ",
		};
		symbolMap[ship] = s[symbolHead++ % 5] + C::reset;
	}
	return symbolMap[ship];
}

void LineInOut::renderBoard(Board* board) {
	cout << "y\\x ";
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " ";
	}
	cout << endl;
	Ship* ship;
	// TODO colorize the ships or use different symbol
	for (unsigned int y = 0; y < BOARD_SIZE; y++) {
		cout << " " << y << "  ";
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			ship = board->isShipAt(Location(x, y));
			if (!ship) {
				cout << "⬚";
			} else {
				cout << getCharForShip(ship);
			}
			cout << " ";
		}
		cout << endl;
	}
}

void LineInOut::askShipLoc(Ship* ship, Board* board) {
	Ship newShip = *ship;
	do {
		cout << "Pick start coordinate of " << C::blue << ship->name << C::reset << " (length " << ship->length << "): ";

		Location start = readLocation();
		cout << "Enter end coordinate: ";
		// TODO offer all 4 options
		Location end = readLocation();

		// TODO do not edit the ship straight away
		// board might return false!
		if (!newShip.setStartEnd(start, end)) {
			cout << "Invalid length, expected " << ship->length << ", try again" << endl;
			continue;
		}
		if (!board->canPlace(&newShip)) {
			cout << "Game rules violation" << endl;
			continue;
		}

		// ok set coords for original ship
		ship->setStartEnd(start, end);
		break;
	} while (true);
}

Location LineInOut::askShot(vector<Shot> shots) {
	renderShots(shots);
	cout << "Fire at: ";
	return readLocation();
}

void LineInOut::renderShots(vector<Shot> shots) {
	cout << "y\\x ";
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " ";
	}
	cout << endl;
	Shot* found;
	for (unsigned int y = 0; y < BOARD_SIZE; y++) {
		cout << " " << y << "  ";
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			found = nullptr;
			for (auto &shot : shots) {
				if (shot.location == Location(x, y)) {
					found = &shot;
					continue;
				}
			}
			if (found && found->response == Response::MISS) {
				cout << "◯ "; // ⎔▢⦁·
			} else if (found) {
				cout << "ⓧ "; // ⬣ⓧⓍ
			} else {
				cout << "⬚ "; // ·
			}
		}
		cout << endl;
	}
}

void LineInOut::renderShotResult(Shot shot) {
	cout << "shot fired at " << shot.location.x << "," << shot.location.y << " ";
	if (shot.response == Response::SUNK) {
		cout << C::blue << "SUNK a ship" << C::reset << endl;
	} else if (shot.response == Response::HIT) {
		cout << C::green << "was a HIT" << C::reset << endl;
	} else {
		cout << "was a miss" << endl;
	}
}
