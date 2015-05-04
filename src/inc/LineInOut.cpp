#include "LineInOut.h"

const Location LineInOut::readLocation() const {
	string answer;

	Location location;
	int res = -1;
	unsigned int x, y;
	do {
		if (res != -1) {
			cout << "enter 'x y' ranged <0, 9>: ";
			cout.flush();
		}

		getline(cin, answer);

		res = sscanf(answer.c_str(), "%u %u", &x, &y);
		if (res == 2) {
			try {
				location = Location(x, y);
			} catch (exception* e) {
				continue;
			}
			break;
		}

	} while (true);

	return location;
}

string LineInOut::ask(string question) const {
	string answer;

	cout << question << " >> ";
	getline(cin, answer);

	return answer;
}

void LineInOut::out(string msg) const {
	cout << msg << endl;
}

void LineInOut::announce(string msg) const {
	cout << C::underline << msg << C::reset << endl;
}

void LineInOut::announceTurn(string msg, unsigned int turn) const {
	announce(msg + " turn " + to_string(turn));
}

string LineInOut::getCharForShip(const Ship* ship) {
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

Ship* LineInOut::isShipAt(vector<Ship> *ships, Location loc) const {
	for (auto &ship : *ships) {
		if (ship.overlaps(loc)) {
			return &ship;
		}
	}
	return nullptr;
}

void LineInOut::renderShips(vector<Ship> ships) {
	cout << "y\\x ";
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " ";
	}
	cout << endl;
	const Ship* ship;
	for (unsigned int y = 0; y < BOARD_SIZE; y++) {
		cout << " " << y << "  ";
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			ship = isShipAt(&ships, Location(x, y));
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

void LineInOut::askShipLoc(Ship* ship) const {
	do {
		Ship newShip = *ship;
		cout << "Pick start coordinate of " << C::blue << ship->name << C::reset << " (length " << ship->length << "): ";

		Location start = readLocation();
		cout << "Enter end coordinate: ";
		// TODO offer all 4 options
		Location end = readLocation();

		if (!newShip.setStartEnd(start, end)) {
			cout << "Invalid length, expected " << ship->length << ", try again" << endl;
			continue;
		}

		ship->setStartEnd(start, end);
		break;
	} while (true);
}

const Location LineInOut::askShot(const vector<Shot> *shots) const {
	renderShots(shots);
	cout << "Fire at: ";
	return readLocation();
}

void LineInOut::renderShots(const vector<Shot> *shots) const {
	cout << "y\\x ";
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " ";
	}
	cout << endl;
	const Shot* found;
	for (unsigned int y = 0; y < BOARD_SIZE; y++) {
		cout << " " << y << "  ";
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			found = nullptr;
			for (auto &shot : *shots) {
				if (shot.location == Location(x, y)) {
					found = &shot;
					continue;
				}
			}
			if (found && found->response == Shot::Response::MISS) {
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

void LineInOut::renderShotResult(const Shot shot) const {
	cout << "shot fired at " << shot.location.x << "," << shot.location.y << " ";
	if (shot.response == Shot::Response::SUNK) {
		cout << C::blue << "SUNK a ship" << C::reset << endl;
	} else if (shot.response == Shot::Response::HIT) {
		cout << C::green << "was a HIT" << C::reset << endl;
	} else {
		cout << "was a miss" << endl;
	}
}

void LineInOut::gameOver(string player) const {
	cout << "GAME OVER" << endl;
	cout << player << " won" << endl;
}
