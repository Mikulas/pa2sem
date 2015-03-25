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

void LineInOut::renderBoard(Board* board) {
	cout << "   ";
	for (unsigned int x = 0; x < BOARD_SIZE; x++) {
		cout << x << " ";
	}
	cout << endl;
	for (unsigned int y = 0; y < BOARD_SIZE; y++) {
		cout << y << "  ";
		for (unsigned int x = 0; x < BOARD_SIZE; x++) {
			cout << (board->isShipAt(Location(x, y)) ? "#" : "_") << " ";
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

Location LineInOut::askShot() {
	cout << "Fire at: ";
	return readLocation();
}

void LineInOut::renderShotResult(Shot shot) {
	if (shot.response == Response::SUNK) {
		cout << C::blue << "shot was SUNK a ship" << C::reset << endl;
	} else if (shot.response == Response::HIT) {
		cout << C::green << "shot was a HIT" << C::reset << endl;
	} else {
		cout << "shot was a miss" << endl;
	}
}
