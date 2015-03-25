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
	cout << underline << msg << reset << endl;
}

void LineInOut::renderBoard() {

}

void LineInOut::askShipLoc(Ship* ship, Board* board) {
	Ship newShip = *ship;
	do {
		cout << "Pick start coordinate of " << blue << ship->name << reset << " (length " << ship->length << "): ";

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
