#ifndef NET_CLIENT_H
#define NET_CLIENT_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "../InOut.h"
#include "../Player/Local.h"
#include "Payload.h"
#include "Server.h"


/**
 * \see Client
 */
class ClientException : public runtime_error {
public:
    ClientException(string const& message)
        : std::runtime_error(message) {}
};


/**
 * Connects to Server and blocks until Server
 * sends a Payload, which is then parsed and appropriate
 * methods are invoked on either LocalPlayer or
 * on InOut.
 */
class Client {
public:
	/**
	 * \throws ClientException connecting to host fails
	 */
	Client(const char *host, LocalPlayer *p, InOut* inOut);
	/**
	 * When `ignoreServer == true`, calls `exit(0)` upon being
	 * disconnected from server.
	 *
	 * \throws ClientException disconnected from server
	 * \throws ClientException unknown method in invoke field
	 * \throws PayloadException
	 */
	void process();

private:
	InOut* inOut;
	/**
	 * \throws ClientException
	 */
	int openCliSocket(const char *host, int port);

	LocalPlayer *player;
	int fd;

	/**
	 * Set to `true` when client recieves GameOver
	 * payload.
	 * When `true`, process quits gracefully when
	 * disconnected from server (as opposed to throwing
	 * exception when set to `false`).
	 */
	bool ignoreServer;
};


#endif
