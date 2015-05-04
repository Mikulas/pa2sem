#include "Controller.h"

Controller::Controller(InOut* inOut, string program)
	: inOut(inOut), program(program), server(new Server()) {}

Controller::~Controller() {
	delete server;
	delete inOut;
	delete game;
}

void Controller::run() {
	string buff;
	Player* players[2];
	vector<RemotePlayer*> remotes;

	for (uint i = 0; i < 2; i++) {
		while (true) {
			string question = "Select player ";
			question += (char) ('A' + i);
			question += ": [human/net/ai1/ai2/ai3]: ";
			buff = inOut->ask(question);

			players[i] = PlayerFactory::from(buff, inOut, server);
			if (players[i] == nullptr) {
				continue;
			}

			if ("net" == buff) {
				remotes.push_back((RemotePlayer*) players[i]);
			}
			break;
		};
	}

	if (remotes.size() != 0) {
		inOut = new InOutBroadcast(inOut, server);

		string addr;
		while (true) {
			addr = inOut->ask("Enter address the server should listen on: [localhost] ");
			if (addr == "") {
				addr = "localhost";
			}

			try {
				server->start(addr.c_str());
				break;

			} catch(ServerException &e) {
				inOut->renderError("Cannot bind to specified interface.");
			}
		}

		string msg = "Waiting for players to connect to ";
		msg += addr;
		msg += ":";
		msg += std::to_string(Server::port);
		inOut->out(msg);

		string info = "Connect with: ";
		info += program;
		info += " ";
		info += addr;
		info += " [player-type]";
		inOut->out(info);

		server->waitForConnections(remotes);
	}

	try {
		// TODO randomize player order?
		this->game = new Game(inOut, players[0], players[1]);
		this->game->gameLoop();

	} catch (ServerException &e) {
		server->stop();
		throw e;
	}
}
