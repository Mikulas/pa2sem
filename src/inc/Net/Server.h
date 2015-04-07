#ifndef SERVER_H
#define SERVER_H

class Server;

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include "../Player/Remote.h"
#include "Payload.h"

using std::vector;
using std::map;


class ServerException {};


/* sekvencni reseni, ketre pomoci funkce select vybira aktivni spojeni. Obsluha jenotlivych
* klientu se (dle pozadavku) strida v case.
*/

class Server {
public:
	void start();
	void stop();
	void waitForConnections(vector<RemotePlayer*>);

	Payload send(RemotePlayer*, Payload*);

	static uint port;

private:
	int fd;
	map<RemotePlayer*, int> sockets;
	int openSrvSocket(const char *name, int port);
};



#endif
