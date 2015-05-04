#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/LineInOut.h"
#include "inc/Net/Client.h"
#include "inc/Net/Client.h"
#include "inc/Net/Server.h"
#include "inc/Player/Factory.h"
#include "lib/Arguments.h"


using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0) + clock());
	auto inOut = new LineInOut;
	Arguments args(argc, argv);

	if (args.flag("help", 'h')) {
		cout << "Usage:" << endl;

		cout << argv[0] << endl;
		cout << "\tRuns local game or server." << endl;

		cout << argv[0] << " server-addr [player-type]" << endl;
		cout << "\t  Connects to game server at server-addr." << endl;
		cout << "\t  Player type defaults to human, all supported values are:" << endl;
		cout << "\t    human, net, ai1, ai2, ai3" << endl;
		return 0;
	}

	auto positional = args.getPositional();
	try {
		if (positional.size() == 1) {
			Controller controller(inOut);
			controller.run();

		} else if (positional.size() == 2) {
			LocalPlayer* player = (LocalPlayer*) PlayerFactory::from("human", inOut);
			Client client(positional.at(1), player, inOut);
			client.process();

		} else if (positional.size() == 3) {
			LocalPlayer* player = (LocalPlayer*) PlayerFactory::from(positional.at(2), inOut);
			if (player == nullptr) {
				inOut->renderError("Unknown player type");
				exit(1);
			}
			Client client(positional.at(1), player, inOut);
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
