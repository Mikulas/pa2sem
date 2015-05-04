#include "InOutBroadcast.h"

void InOutBroadcast::out(string msg) const {
	inOut->out(msg);
}

void InOutBroadcast::announce(string msg) const {
	inOut->announce(msg);

	Payload p;
	p << Payload::Invoke::IOAnnounce;
	p << msg;
	server->sendAll(&p);
}

void InOutBroadcast::announceTurn(string msg, unsigned int turn) const {
	inOut->announceTurn(msg, turn);

	Payload p;
	p << Payload::Invoke::IOAnnounceTurn;
	p << turn;
	p << msg;
	server->sendAll(&p);
}

void InOutBroadcast::renderShips(vector<Ship> ships) {
	inOut->renderShips(ships);
}

string InOutBroadcast::ask(string question) const {
	return inOut->ask(question);
}

void InOutBroadcast::askShipLoc(Ship* ship) const {
	inOut->askShipLoc(ship);
}

const Location InOutBroadcast::askShot(const vector<Shot> *shots) const {
	return inOut->askShot(shots);
}

void InOutBroadcast::renderShotResult(const Shot shot) const {
	inOut->renderShotResult(shot);

	Payload p;
	p << Payload::Invoke::IOShotResult;
	p << shot;
	server->sendAll(&p);
}

void InOutBroadcast::gameOver(string player) const {
	inOut->gameOver(player);

	Payload p;
	p << Payload::Invoke::IOGameOver;
	p << player;
	server->sendAll(&p);
}
