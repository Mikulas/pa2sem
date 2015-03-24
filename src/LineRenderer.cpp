#include "LineRenderer.h"

string LineRenderer::ask(string question) {
	string answer;

	cout << question << " >> ";
	getline(cin, answer);

	return answer;
}

void LineRenderer::renderBoard() {

}


