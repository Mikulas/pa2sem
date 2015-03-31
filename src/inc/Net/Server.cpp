#include "Server.h"

int Server::getPort() {
    return port;
}

/**
 * \throws ServerException
 */
void Server::start() {
	for (port = PORT_MIN; port <= PORT_MAX; port++) {
		 fd = openSrvSocket("127.0.0.1", port);
		 if (fd >= 0) {
		 	break;
		 }
	}
	if (fd < 0) {
		// failed to open any of the ports in range
		throw ServerException();
	}

	struct sockaddr remote;
	socklen_t remoteLen = sizeof (remote);
printf("going to accept on port %d\n", port);
	this->fd = accept(fd, &remote, &remoteLen);
printf("accepted\n");
}

void Server::invoke(const char* method) const {
printf("writing '%s'\n", method);
	// TODO send method name
	write(this->fd, method, strlen(method) * sizeof(char));
printf("wrote '%s'\n", method);
	char buffer[200];
printf("reading\n");
	int l = read(this->fd, buffer, sizeof(buffer));
printf("read %s\n", buffer);
	if (!l) {
		// nulova delka -> uzavreni spojeni klientem
		// TODO
	}
	printf("received: '%s'\n", buffer);
}

void Server::stop() {
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
