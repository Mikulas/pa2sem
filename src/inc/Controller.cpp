#include "Controller.h"

Controller::Controller(InOut* inOut) {
	this->inOut = inOut;
	this->server = new Server();
}

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
			question += ": [human/net/ai1/ai2]: ";
			buff = inOut->ask(question);
			if ("human" == buff) {
				players[i] = new HumanPlayer(inOut);

			} else if ("net" == buff) {
				RemotePlayer *p = new RemotePlayer(server);
				players[i] = p;
				remotes.push_back(p);

			} else if ("ai1" == buff) {
				players[i] = new RandomAIPlayer();

			} else if ("ai2" == buff) {
				players[i] = new RandomWithMemoryAIPlayer();

			} else {
				continue;
			}
			break;
		};
	}

	if (remotes.size() != 0) {
		inOut = new InOutBroadcast(inOut, server);
		server->start();
		server->waitForConnections(remotes);
	}

	try {
		// TODO randomize player order?
		this->game = new Game(inOut, players[0], players[1]);
		this->game->gameLoop();

	} catch (ServerException &e) {
		// TODO inform user
		server->stop();
		exit(1);
	}
}
