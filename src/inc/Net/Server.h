#ifndef SERVER_H
#define SERVER_H

#include <cctype>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_MIN 5037 // unassigned http://www.speedguide.net/port.php?port=5037
#define PORT_MAX 5040


class ServerException {};

/**
 * \exception ServerException
 * Implementations taken from https://edux.fit.cvut.cz/courses/BI-PA2/semestralka
 */
class Server {
public:
	/**
 	 * \throws ServerException
 	 */
	void start();
	void invoke(const char* method) const;
	void stop();
	int getPort();

private:
	int port;
	int fd;
	int openSrvSocket(const char *name, int port);
};


#endif
