#include "Server.h"

/**
 * \throws ServerException
 */
void Server::start() {
	// TODO create new thread

	int fd = openSrvSocket("127.0.0.1", PORT);
	if (fd < 0) {
		throw ServerException();
	}

	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);

	while(1) {
		struct sockaddr remote;
		socklen_t remoteLen = sizeof (remote);
		Thread* thread = new Thread;
		thread->fd = accept(fd, &remote, &remoteLen);
		printf("New connection\n");
		pthread_create(&thread->thr, &attr, (void*(*)(void*)) serveClient, (void*) thread);
    }
	pthread_attr_destroy (&attr);
	close(fd);
}

int Server::openSrvSocket(const char *name, int port)
{
	struct addrinfo *ai;
	char portStr[10];

	/* Adresa, kde server posloucha. Podle name se urci typ adresy
     * (IPv4/6) a jeji binarni podoba
     */
    snprintf(portStr, sizeof(portStr), "%d", port);
    if (getaddrinfo(name, portStr, NULL, &ai)) {
    	printf("addrinfo\n");
    	return -1;
    }
	/* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
     * stream = TCP
     */
    int fd = socket(ai->ai_family, SOCK_STREAM, 0);
    if (fd == -1) {
    	freeaddrinfo(ai);
    	printf("socket\n");
    	return -1;
    }

    /* napojeni soketu na zadane sitove rozhrani
     */
    if (::bind(fd, ai->ai_addr, ai->ai_addrlen) == -1) {
    	close(fd);
    	freeaddrinfo(ai);
    	printf("bind\n");
    	return -1;
    }
    freeaddrinfo(ai);
	/* prepnuti soketu na rezim naslouchani (tedy tento soket nebude vyrizovat
     * datovou komunikaci, budou po nem pouze chodit pozadavky na pripojeni.
     * 10 je max velikost fronty cekajicich pozadavku na pripojeni.
     */
    if (listen(fd, 10) == -1) {
    	close(fd);
    	printf("listen\n");
    	return -1;
    }
    return fd;
}

/* obsluha jednoho klienta (vsechny jeho zpravy)
 */
void *Server::serveClient(Thread *thread) {
	char buffer[200];
	while (1) {
		int l = read(thread->fd, buffer, sizeof(buffer));
		// nulova delka -> uzavreni spojeni klientem
		if (!l) {
			break;
		}

		// prevod mala -> velka a naopak
		for (int i = 0; i < l; i ++) {
			if (isalpha(buffer[i])) {
				buffer[i] ^= 0x20;
			}
		}
		write(thread->fd, buffer, l);
		// spojeni nebylo ukonceno, jeste mohou prijit dalsi data.
	}
	close(thread->fd);
	printf("Close connection\n");
	return NULL;
}
