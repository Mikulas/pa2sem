#ifndef SERVER_H
#define SERVER_H

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include "InOut.h"

#define PORT 5037 // unassigned http://www.speedguide.net/port.php?port=5037

using namespace std;


class ServerException {};


struct Thread
{
	pthread_t thr;
	int fd;
};

/**
 * \exception ServerException
 */
class Server {
public:
	Server(InOut* inOut) : inOut(inOut) {};
	void start();

private:
	int openSrvSocket(const char *name, int port);
	static void *serveClient(Thread*);
	InOut* inOut;
};


#endif
