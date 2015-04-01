#include <stdlib.h>
#include <time.h>
#include "inc/Net/Client.h"
#include "inc/Controller.h"
#include "inc/LineInOut.h"
#include "inc/Player/AI/RandomWithMemory.h"


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
	auto inOut = new LineInOut;

	if (argc == 1) {
		Controller controller(inOut);
		controller.run();

	} else if (argc == 2 || argc == 3) {
		Player* player = new RandomWithMemoryAIPlayer(inOut);
		Client* client = new Client(player);
		player->setOpponent(client);

		if (argc == 3) {
			client->connect(argv[1], stoi(argv[2]));

		} else {
			client->connect(argv[1]);
		}

	} else {
		cerr << "Usage: " << argv[0] << endl;
		cerr << "            - starts a new game" << endl;
		cerr << "       " << argv[0] << " [server ip] [port]" << endl;
		cerr << "            - connects to an existing game server" << endl;
		return 1;
	}

	return 0;
}
