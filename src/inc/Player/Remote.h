#ifndef REMOTEPLAYER
#define REMOTEPLAYER

class RemotePlayer;

#include "Player.h"
#include "../Net/Server.h"


class RemotePlayer : public Player
{
public:
	RemotePlayer(Server *server) : server(server) {};
	virtual vector<Ship> setup(vector<Ship>) override;
	virtual Location takeTurn() override;
	virtual void saveShot(Shot) override;
private:
	Server* server;
};


#endif
