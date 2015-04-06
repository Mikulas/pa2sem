#ifndef SERVER_H
#define SERVER_H

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using std::vector;


class ServerException {};


/* sekvencni reseni, ketre pomoci funkce select vybira aktivni spojeni. Obsluha jenotlivych
* klientu se (dle pozadavku) strida v case.
*/

class Server {
public:
	void start();
	void stop();
	void waitForConnections(int count);

	static uint port;

private:
	vector<int> sockets;
	int openSrvSocket(const char *name, int port);
};



#endif