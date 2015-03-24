#include "LineInOut.h"

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

	string answer;
	getline(cin, answer);

	cout << "you wrote '" << answer << "'" << endl;

	// TODO catch exceptions, loop on error
	// TODO return user input
	return Ship(ship, Location(0, 0), Location(0, length));
}

Location LineInOut::askShot() {
	cout << "Fire at: ";

	string answer;
	getline(cin, answer);

	cout << "you wrote '" << answer << "'" << endl;

	// TODO catch exceptions, loop on error
	// TODO return user input
	return Location(0, 0);
}
