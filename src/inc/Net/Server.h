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

#define PORT 5037 // unassigned http://www.speedguide.net/port.php?port=5037


class ServerException {};

/**
 * \internal
 */
struct Thread
{
	pthread_t thr;
	int fd;
};

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

private:
	int openSrvSocket(const char *name, int port);
	static void *serveClient(Thread*);
};


#endif
