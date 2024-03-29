#include "Server.h"

uint Server::port = 10451;

int Server::openSrvSocket(const char *name, int port)
{
	struct addrinfo * ai;
	char portStr[10];

	/* Adresa, kde server posloucha. Podle name se urci typ adresy
	 * (IPv4/6) a jeji binarni podoba
	 */
	snprintf(portStr, sizeof(portStr), "%d", port);
	if (getaddrinfo(name, portStr, NULL, &ai)) {
		throw ServerException("Invalid hostname");
	}

	/* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
	 * stream = TCP
	 */
	int fd = socket(ai->ai_family, SOCK_STREAM, 0);
	if (fd == -1) {
		freeaddrinfo(ai);
		throw ServerException("Failed to open socket");
	}

	/* napojeni soketu na zadane sitove rozhrani
	*/
	if (bind(fd, ai->ai_addr, ai->ai_addrlen) == -1) {
		close(fd);
		freeaddrinfo(ai);
		throw ServerException("Failed to bind to socket");
	}

	freeaddrinfo(ai);
	/* prepnuti soketu na rezim naslouchani (tedy tento soket nebude vyrizovat
	 * datovou komunikaci, budou po nem pouze chodit pozadavky na pripojeni.
	 * 10 je max velikost fronty cekajicich pozadavku na pripojeni.
	 */
	if (listen(fd, 10) == -1)
	{
		close(fd);
		throw ServerException("Failed to listen on socket");
	}
	return fd;
}

void Server::start() {
	start("localhost");
}

void Server::start(const char *addr) {
	fd = openSrvSocket(addr, Server::port);
	if (fd < 0) {
		throw ServerException("Failed to start server");
	}
}

void Server::stop() {
	for (auto &pair : sockets) {
		close(pair.second);
	}
}

void Server::waitForConnections(vector<RemotePlayer*> players) {
	while(true) {
		fd_set rd;
		int max = fd;

		// vyplnime mnozinu soketu, ktere nas zajimaji
		FD_ZERO(&rd);
		FD_SET(fd, &rd);
		for (auto &pair : sockets) {
			FD_SET(pair.second, &rd);
			if (pair.second > max) {
				max = pair.second;
			}
		}

		// cekame, dokud na nejakem ze soketu nejsou k dispozici data
		// pokud nejsou->proces bude uspan a nebude zadat o procesorovy cas.
		int res = select(max + 1, &rd, NULL, NULL, NULL);
		if (res > 0) {
			// data na soketu sockets[0]->nove pripojeny klient
			if (FD_ISSET(fd, &rd)) {
				struct sockaddr remote;
				socklen_t remoteLen = sizeof(remote);

				// vytvorime spojeni k tomuto klientu, accept vraci novy soket, kterym
				// zasilame data pouze v tomto spojeni
				int dataFd = accept(fd, &remote, &remoteLen);
				printf("New connection\n");

				sockets[players.back()] = dataFd;
				players.pop_back();
				if (players.size() == 0) {
					return;
				}
			}
		}
	}
}

Payload Server::send(RemotePlayer* player, Payload* payload) {
	const char *data = payload->data();
	write(sockets[player], data, payload->size());
	delete[] data;

	char buffer[500];
	int l = read(sockets[player], buffer, sizeof(buffer));

	if (l <= 0) {
		throw ServerException("Player disconnected.");
	}
	Payload response(buffer, l);

	return response;
}

void Server::sendAll(Payload* payload) {
	for (auto &pair : sockets) {
		send(pair.first, payload);
	}
}
