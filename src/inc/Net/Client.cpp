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
	this->port = port;
	int fd = openCliSocket(name.c_str(), port);
	if (fd < 0) {
		throw ClientException();
	}

	printf("connected to server on port %d\n", port);

	char buffer[200];

	while (true) {
		memset(&buffer, 0, sizeof(buffer));
		int l = read(fd, buffer, sizeof(buffer));
		if (!l) {
			break;
		}

		printf("received: '%s'\n", buffer);
		if (0 == strcmp(buffer, "setup")) {
			player->setup();

		} else if (0 == strcmp(buffer, "takeTurn")) {
			player->takeTurn();

		} else {
			printf("unknown '%s'\n", buffer);
			throw ClientException();
		}

		snprintf(buffer, sizeof(buffer), "%d: %s\n", 1337, "Ahoj Mikulasi");
		write(fd, buffer, strlen(buffer));
		printf("wrote '%s'\n", buffer);
	}

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

//
// Player implementations
//

void Client::setup() {
	// TODO
}

void Client::takeTurn() {
	// TODO
}

const Shot Client::respond(const Location) {
	// TODO
}

bool Client::allShipsSunk() const {
	// TODO
	return false;
}
