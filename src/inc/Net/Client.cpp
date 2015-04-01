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

	const uint size = 1000;
	char* buffer = (char*) malloc(size);

	while (true) {
		memset(&buffer, 0, size);
		int l = read(fd, buffer, size);
		if (!l) {
			break;
		}

		Payload payload = Payload::read((const unsigned char*)buffer);
printf("%s\n", "payload parsed!");


		printf("received: '%s'\n", buffer);
		if (0 == strcmp(buffer, "setup")) {
			player->setup();

		} else if (0 == strcmp(buffer, "takeTurn")) {
			player->takeTurn();

		} else if (0 == strcmp(buffer, "respond")) {
			// TODO read location from received
			//player->respond(location);
			// TODO send response back

		} else if (0 == strcmp(buffer, "allShipsSunk")) {
			player->allShipsSunk();
			// TODO send response back

		} else {
			printf("unknown '%s'\n", buffer);
			throw ClientException();
		}

		snprintf(buffer, size, "%d: %s\n", 1337, "Ahoj Mikulasi");
		write(fd, buffer, strlen(buffer));
		printf("wrote '%s'\n", buffer);
	}

	free(buffer);

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

/**
 * Does not need to do anything,
 * setup is done on remote instance by
 * other implementation of Player
 */
void Client::setup() {}

/**
 * Does not need to do anything,
 * setup is done on remote instance by
 * other implementation of Player
 */
void Client::takeTurn() {}

const Shot Client::respond(const Location) {
	// TODO
}

bool Client::allShipsSunk() const {
	// TODO
	return false;
}
