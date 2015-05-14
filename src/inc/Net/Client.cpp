#include "Client.h"

Client::Client(string host, LocalPlayer *player, InOut* inOut) {
    fd = openCliSocket(host.c_str(), Server::port);
    if (fd < 0) {
        throw ClientException("Failed connecting to server");
    }

    this->ignoreServer = false;
    this->player = player;
    this->inOut = inOut;
}

void Client::process() {
    char buffer[500];
    Payload::Invoke invoke;
    int l;

    while (true) {
        l = read(fd, buffer, sizeof(buffer));
        if (l <= 0) {
            if (ignoreServer) {
                exit(0);
            }
            throw ClientException("Disconnected");
        }

        Payload response;
        try {
            Payload payload(buffer, l);
            payload >> invoke;

            if (invoke == Payload::Invoke::Setup) {
                vector<Ship> ships;
                payload >> ships;
                auto placed = player->setup(ships);
                response << placed;

            } else if (invoke == Payload::Invoke::TakeTurn) {
                auto target = player->takeTurn();
                response << target;

            } else if (invoke == Payload::Invoke::SaveShot) {
                Shot shot;
                payload >> shot;
                player->saveShot(shot);

                response << Payload::Field::Ack;

            } else if (invoke == Payload::Invoke::IOAnnounce) {
                string msg;
                payload >> msg;
                inOut->announce(msg);

            } else if (invoke == Payload::Invoke::IOAnnounceTurn) {
                int turn;
                string msg;
                payload >> turn;
                payload >> msg;
                inOut->announceTurn(msg, turn);

            } else if (invoke == Payload::Invoke::IOShotResult) {
                Shot shot;
                payload >> shot;
                inOut->renderShotResult(shot);

            } else if (invoke == Payload::Invoke::IOGameOver) {
                ignoreServer = true;
                string player;
                payload >> player;
                inOut->gameOver(player);

            } else {
                throw ClientException("Invalid method invoked");
            }

        } catch (PayloadException &e) {
            if (ignoreServer) {
                exit(0);
            }
            throw e;
        }


        const char *data = response.data();
        write(fd, data, response.size());
        delete[] data;
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
        throw ClientException("Invalid host or server not running");
    }

    /* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
     * stream = TCP
     */
    int fd = socket(ai->ai_family, SOCK_STREAM, 0);
    if (fd == -1) {
        freeaddrinfo(ai);
        throw ClientException("Socket failure");
    }
    /* Zadost o spojeni se serverem (ted se teprve zacne komunikovat).
     * vysledkem je bud otevrene datove spojeni nebo chyba.
     */
    if (connect(fd, ai->ai_addr, ai->ai_addrlen) == - 1) {
        close(fd);
        freeaddrinfo(ai);
        throw ClientException("Connection failure");
    }
    freeaddrinfo(ai);
    return fd;
}
