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

using std::string;


class ClientException {};


/**
 * \exception ClientException
 */
class Client {
public:
	/**
	 * \throws ClientException
	 */
	void connect(string name);
	void connect(string name, int port);

private:
	int port;
	int openCliSocket(const char* name, int port);
};


#endif
