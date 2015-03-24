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

Ship LineInOut::askShipLoc(int length, string ship) {
	cout << "Pick position of " << blue << ship << reset << " (" << length << "): ";

	Location loc = readLocation();

	// TODO ask for second coordinate
	return Ship(ship, loc, Location(loc.x, loc.y + 5));
}

Location LineInOut::askShot() {
	cout << "Fire at: ";
	return readLocation();
}
