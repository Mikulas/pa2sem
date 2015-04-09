#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/LineInOut.h"
#include "inc/Net/Client.h"
#include "inc/Net/Client.h"
#include "inc/Net/Server.h"
#include "inc/Player/Factory.h"


using namespace std;

/*! \mainpage Battleship
 *
 * \section intro_sec Introduction
 *
 * Seminar work BI-PA2 2015
 *
 * \section install_sec Build
 *
 * Build with `make`
 *
 * \section run_sec Running
 * \subsection run_server Local game or Server
 * Execute interactive game interface as `make run`
 * or manually call `./build/lode`
 *
 * \subsection run_client Remote game
 * To connect to a remote server, call
 * `./build/lode server [Type]`
 * where `Type` is one of (`human`, `ai1`, `ai2`).
 *
 * \defgroup Utility Utility
 * \defgroup Player Player
 * \defgroup Net Net
 */
int main(int argc, char **argv)
{
	srand(time(0) + clock());

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
				exit(1);
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
