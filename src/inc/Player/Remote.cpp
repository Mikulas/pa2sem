#include "Remote.h"

vector<Ship> RemotePlayer::setup(vector<Ship> ships) {
	Payload request;
	request << Payload::Invoke::Setup;
	request << ships;
	Payload response = server->send(this, &request);

	vector<Ship> placed;
	response >> placed;
	return placed;
}

Location RemotePlayer::takeTurn() {
	Payload request;
	request << Payload::Invoke::TakeTurn;
	Payload response = server->send(this, &request);

	Location target;
	response >> target;
	return target;
}

void RemotePlayer::saveShot(Shot shot) {
	Payload request;
	request << Payload::Invoke::SaveShot;
	request << shot;
	server->send(this, &request);
}
