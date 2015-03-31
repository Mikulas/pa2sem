#include "Client.h"

void Client::connect(string name) {
	for (int port = PORT_MAX; port >= PORT_MIN; port--) {
		// intentionally trying unopened ports first
		// as we want users on different ports

		try {
			connect(name, port);
			return;

		} catch(ClientException &e) {
			// ok, try another
		}
	}
	throw ClientException();
}

void Client::connect(string name, int port) {
	int fd;

	this->port = port;
	openCliSocket(name.c_str(), port);
	if (fd < 0) {
		throw ClientException();
	}

printf("connected to server on port %d\n", port);

	char buffer[200];

	int l = read(fd, buffer, sizeof(buffer));
printf("received:\n");
	write(STDOUT_FILENO, buffer, l);
printf("\n<<<end");

	snprintf(buffer, sizeof(buffer), "%d: %s\n", 1337, "Ahoj Mikulasi");
printf("writing:\n");
	write(fd, buffer, strlen(buffer));
printf("wrote\n");

	// uzavreni spojeni klientem. Server zjisti uzavreni spojeni a
	// uvolni prostredky na sve strane.
	close(fd);
}

int Client::openCliSocket(const char * name, int port)
{
	struct addrinfo * ai;
	char portStr[10];

	/* Adresa, kde server posloucha. Podle name se urci typ adresy
	 * (IPv4/6) a jeji binarni podoba
	 */
	snprintf(portStr, sizeof(portStr), "%d", port);
	if (getaddrinfo(name, portStr, NULL, &ai)) {
		printf("fail: addrinfo\n");
		return -1;
	}
	/* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
	 * stream = TCP
	 */
	int fd = socket(ai->ai_family, SOCK_STREAM, 0);
	if (fd == -1) {
		freeaddrinfo(ai);
		printf("fail: socket\n");
		return -1;
	}
	/* Zadost o spojeni se serverem (ted se teprve zacne komunikovat).
	 * vysledkem je bud otevrene datove spojeni nebo chyba.
	 */
	if (::connect(fd, ai->ai_addr, ai->ai_addrlen) == - 1) {
		close(fd);
		freeaddrinfo(ai);
		printf("fail: connect\n");
		return -1;
	}
	freeaddrinfo(ai);
	return fd;
}
