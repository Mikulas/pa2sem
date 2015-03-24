#include "LineInOut.h"

Location LineInOut::readLocation() {
	string answer;
	
	int res = -1;
	int x, y;
	do {
		if (res != -1) {
			cout << "enter 'x y' ranged <0, 9>: ";
			cout.flush();
		}

		getline(cin, answer);

		res = sscanf(answer.c_str(), "%d %d", &x, &y);
	} while (res != 2 || x < 0 || x >= 10 || y < 0 || y >= 10);

	return Location(x, y);
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

void LineInOut::askShipLoc(Ship* ship) {
	do {
		cout << "Pick position of " << blue << ship->name << reset << " (length " << ship->length << "): ";

		Location start = readLocation();
		Location end = readLocation();

		if (!ship->setStartEnd(start, end)) {
			break;
		}
		cout << "Invalid length, expected " << ship->length << ", try again" << endl;
	} while (true);
}

Location LineInOut::askShot() {
	cout << "Fire at: ";
	return readLocation();
}
