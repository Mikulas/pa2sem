#include "Controller.h"

Controller::Controller(InOut* inOut) {
	this->inOut = inOut;
}

Controller::~Controller() {
	delete this->inOut;
	delete this->game;
}

void Controller::run() {
	string buff;
	Player* players[2];
	int remotePlayers = 0;
	for (uint i = 0; i < 2; i++) {
		while (true) {
			string question = "Select player ";
			question += (char) ('A' + i);
			question += ": [human/net/ai1/ai2]: ";
			buff = inOut->ask(question);
			if ("human" == buff) {
				players[i] = new HumanPlayer(inOut);

			} else if ("net" == buff) {
				players[i] = new RemotePlayer();
				remotePlayers++;

			} else if ("ai1" == buff) {
				players[i] = new RandomAIPlayer(inOut);

			} else if ("ai2" == buff) {
				players[i] = new RandomWithMemoryAIPlayer(inOut);

			} else {
				continue;
			}
			break;
		};
	}

	if (remotePlayers) {
		server = new Server();
printf("starting server\n"); // todo move to InOut
		server->start();
printf("waiting for %d playres\n", remotePlayers); // todo move to InOut
		server->waitForConnections(remotePlayers);
	}
printf("running game\n"); // todo move to InOut

	// TODO randomize player order?
	this->game = new Game(inOut, players[0], players[1]);
	this->game->gameLoop();
}
