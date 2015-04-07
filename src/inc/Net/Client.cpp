#include "Client.h"

void Client::process() {
    char buffer[500];
    Invoke invoke;
    int l;

    while (true) {
        l = read(fd, buffer, sizeof(buffer));
        if (l <= 0) {
            // TODO
        }

        Payload payload(buffer, l);
        printf("received ");
        payload.debug();

        payload >> invoke;

        Payload response;
        if (invoke == Invoke::Setup) {
            vector<Ship> ships;
            payload >> ships;
            auto placed = player->setup(ships);
            response << placed;

        } else if (invoke == Invoke::TakeTurn) {
            auto target = player->takeTurn();
            response << target;

        } else if (invoke == Invoke::SaveShot) {
            Shot shot;
            payload >> shot;
            player->saveShot(shot);

            continue; // does not expect response
        }

        printf("sending ");
        response.debug();
        auto data = response.data();
        write(fd, data, response.size());
        delete data;
    }

    close(fd);
}

int Client::openCliSocket(const char * host, int port) {
   struct addrinfo * ai;
   char portStr[10];

    /* Adresa, kde server posloucha. Podle host se urci typ adresy
     * (IPv4/6) a jeji binarni podoba
     */
    snprintf(portStr, sizeof(portStr), "%d", port);
    if (getaddrinfo(host, portStr, NULL, &ai)) {
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
    /* Zadost o spojeni se serverem (ted se teprve zacne komunikovat).
     * vysledkem je bud otevrene datove spojeni nebo chyba.
     */
    if (connect(fd, ai->ai_addr, ai->ai_addrlen) == - 1) {
        close(fd);
        freeaddrinfo(ai);
        printf("connect\n");
        return -1;
    }
    freeaddrinfo(ai);
    return fd;
}

Client::Client(const char *host, LocalPlayer *player) {
    fd = openCliSocket(host, Server::port);
    if (fd < 0) {
        throw ClientException();
    }

    this->player = player;
}
