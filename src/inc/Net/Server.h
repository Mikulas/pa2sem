#ifndef NET_SERVER_H
#define NET_SERVER_H

class Server;

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include "../Player/Remote.h"
#include "Payload.h"

using std::map;
using std::vector;


/**
 * \see Server
 * \ingroup Net
 */
class ServerException : public runtime_error {
public:
    ServerException(string const& message)
        : std::runtime_error(message) {}
};


/**
 * Communicates with one or multiple Client instances via Payload.
 * Listens on one port. Since all communication with user
 * must be blocking (with the exception of sending output),
 * all methods are called on the main thread.
 *
 * \ingroup Net
 */
class Server {
public:
	Server() {};
	/**
	 * Starts listening on socket, but does not wait for
	 * any connection.
	 * \see waitForConnections
	 * \throws ServerException
	 */
	void start();
	/**
	 * Silently disconnects all users, if any.
	 */
	void stop();
	/**
	 * Blocks until there are as many connections
	 * as passed `RemotePlayer*`.
	 * There is no guarantee which player is bound to
	 * which socket, the order is random (depends on
	 * order in which users connect).
	 */
	void waitForConnections(vector<RemotePlayer*>);

	/**
	 * \see Payload
	 * \throws ServerException player disconnected
	 * \throws PayloadException
	 */
	Payload send(RemotePlayer*, Payload*);
	/**
	 * \see Payload
	 * \throws ServerException player disconnected
	 * \throws PayloadException
	 */
	void sendAll(Payload*);

	static uint port;

private:
	/**
	 * \throws ServerException
	 */
	int openSrvSocket(const char *name, int port);

	int fd;
	map<RemotePlayer*, int> sockets;
};



#endif
