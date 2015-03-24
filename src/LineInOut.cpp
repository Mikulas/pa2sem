#include "LineInOut.h"

string LineInOut::ask(string question) {
	string answer;

	cout << question << " >> ";
	getline(cin, answer);

	return answer;
}

void LineInOut::announce(string msg) {
	cout << msg << endl;
}

void LineInOut::renderBoard() {

}

Ship LineInOut::askShipLoc(int length, string ship) {
	cout << "Pick position of " << ship << " (" << length << "): ";

	string answer;
	getline(cin, answer);

	cout << "you wrote '" << answer << "'" << endl;

	return Ship(ship, Location(0, 0), Location(0, length));
}
