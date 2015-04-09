#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/LineInOut.h"
#include "inc/Net/Client.h"
#include "inc/Net/Client.h"
#include "inc/Net/Server.h"
#include "inc/Player/Factory.h"


using namespace std;

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
