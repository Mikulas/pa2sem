#ifndef CLIENT_H
#define CLIENT_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdexcept>
#include "Server.h"
#include "Payload.h"
#include "../InOut.h"
#include "../Player/Local.h"


class ClientException : public runtime_error {
public:
    ClientException(string const& message)
        : std::runtime_error(message) {}
};


class Client {
public:
	Client(const char *host, LocalPlayer *p, InOut* inOut);
	void process();

private:
	InOut* inOut;
	int openCliSocket(const char *host, int port);

	LocalPlayer *player;
	int fd;
	bool ignoreServer;
};


#endif
