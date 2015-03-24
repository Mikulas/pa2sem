#include "LineInOut.h"

string LineInOut::ask(string question) {
	string answer;

	cout << question << " >> ";
	getline(cin, answer);

	return answer;
}

void LineInOut::renderBoard() {

}

Ship LineInOut::askShipLoc(int length, string ship) {
	cout << "Pick position of " << ship << " (" << length << "): ";
}
