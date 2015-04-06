#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "Server.h"


class ClientException {};


class Client {
public:
	Client(const char *name);
	void process();

private:
	int openCliSocket(const char *name, int port);

	int fd;
};
