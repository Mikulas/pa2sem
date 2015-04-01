#ifndef CLIENT_H
#define CLIENT_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "Server.h"
#include "../Player/Player.h"
#include "../InOut.h"

using std::string;


class ClientException {};


/**
 * \exception ClientException
 */
class Client : public Player {
public:
	Client(Player* player) : player(player) {}

	/**
	 * \throws ClientException
	 */
	void connect(string name);
	void connect(string name, int port);

	// Player
	virtual const Shot respond(const Location) override;
    virtual void setup() override;
	virtual void takeTurn() override;
	virtual bool allShipsSunk() const override;

private:
	int port;
	int openCliSocket(const char* name, int port);
	Player* player;
};


#endif
