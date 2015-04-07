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
		printf("addrinfo\n");
		return -1;
	}

	/* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
	 * stream = TCP
	 */
	int fd = socket(ai -> ai_family, SOCK_STREAM, 0);
	if (fd == -1) {
		freeaddrinfo(ai);
		printf("socket\n");
		return -1;
	}

	/* napojeni soketu na zadane sitove rozhrani
	*/
	if (bind(fd, ai -> ai_addr, ai -> ai_addrlen) == -1) {
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
	if (listen(fd, 10) == -1)
	{
		close(fd);
		printf("listen\n");
		return -1;
	}
	return fd;
}

/* obsluha jednoho klienta. Vyzvedne (cast) dat zaslanou
 * klientem a zpracuje ji.
 */
bool serveClient(int dataFd)
{
	char buffer[200];
	int l = read(dataFd, buffer, sizeof(buffer));

	// nulova delka -> uzavreni spojeni klientem
	if (! l) {
		return false;
	}

	// prevod mala -> velka a naopak
	for(int i = 0; i < l; i ++) {
		if (isalpha(buffer[i])) {
			buffer[i] ^= 0x20;
		}
		write(dataFd, buffer, l);
	}

	// spojeni nebylo ukonceno, jeste mohou prijit dalsi data.
	return true;
}

void Server::start() {
	fd = openSrvSocket("localhost", Server::port);
	if (fd < 0) {
		throw ServerException();
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
		// pokud nejsou -> proces bude uspan a nebude zadat o procesorovy cas.
		int res = select(max + 1, &rd, NULL, NULL, NULL);
		if (res > 0) {
			// data na soketu sockets[0] -> nove pripojeny klient
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
	write(sockets[player], payload->data(), payload->size());

	char buffer[200];
	int l = read(sockets[player], buffer, sizeof(buffer));

	// nulova delka -> uzavreni spojeni klientem
	if (!l) {
		return Payload(); // TODO fix
	}

	return Payload(buffer);
}
