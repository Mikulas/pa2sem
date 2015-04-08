#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/Net/Client.h"
#include "inc/LineInOut.h"

#include "inc/Net/Server.h"
#include "inc/Net/Client.h"
#include "inc/Player/Factory.h"


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
			LocalPlayer* player = (LocalPlayer*) PlayerFactory::from("human", inOut);
			Client client(argv[1], player, inOut);
			client.process();

		} else if (argc == 3) {
			LocalPlayer* player = (LocalPlayer*) PlayerFactory::from(argv[2], inOut);
			if (player == nullptr) {
				inOut->renderError("Unknown player type");
			}
			Client client(argv[1], player, inOut);
			client.process();
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
