#include <stdlib.h>
#include <time.h>
#include "inc/Net/Client.h"
#include "inc/Controller.h"
#include "inc/LineInOut.h"


using namespace std;

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */
int main(int argc, char **argv)
{
	srand(time(NULL));
	auto renderer = new LineInOut;

	if (argc == 1) {
		Controller controller(renderer);
		controller.run();

	} else if (argc == 2) {
		Client* client = new Client();
		client->connect(argv[1]);

	} else if (argc == 3) {
		Client* client = new Client();
		client->connect(argv[1], stoi(argv[2]));

	} else {
		cerr << "Usage: " << argv[0] << endl;
		cerr << "            - starts a new game" << endl;
		cerr << "       " << argv[0] << " [server ip] [port]" << endl;
		cerr << "            - connects to an existing game server" << endl;
		return 1;
	}

	return 0;
}
