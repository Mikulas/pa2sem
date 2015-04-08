#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/Net/Client.h"
#include "inc/LineInOut.h"

#include "inc/Net/Server.h"
#include "inc/Net/Client.h"
#include "inc/Player/AI/Random.h"
#include "inc/Player/Human.h"


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

	try {
		if (argc == 1) {
			Controller controller(inOut);
			controller.run();

		} else if (argc == 2) {
			// LocalPlayer* player = new RandomAIPlayer();
			LocalPlayer* player = new HumanPlayer(inOut);
			Client client(argv[1], player, inOut); // TODO catch exc
			client.process();

		} else if (argc == 3) {
		}

	} catch (ServerException &e) {
		inOut->renderError(e);

	} catch (ClientException &e) {
		inOut->renderError(e);

	} catch (PayloadException &e) {
		inOut->renderError(e);
	}

	return 0;
}
