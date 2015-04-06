#include "Client.h"

int Client::openCliSocket(const char * name, int port) {
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
    /* Zadost o spojeni se serverem (ted se teprve zacne komunikovat).
     * vysledkem je bud otevrene datove spojeni nebo chyba.
     */
    if (connect(fd, ai -> ai_addr, ai -> ai_addrlen) == - 1) {
        close(fd);
        freeaddrinfo(ai);
        printf("connect\n");
        return -1;
    }
    freeaddrinfo(ai);
    return fd;
}

Client::Client(const char *name) {
    fd = openCliSocket(name, Server::port);
    if (fd < 0) {
        throw ClientException();
    }
}

void Client::process() {
    while (true) {
        char buffer[200];
        snprintf(buffer, sizeof(buffer), "%d: %s\n", 1337, "Hello World");
        write(fd, buffer, strlen(buffer));

        int l = read(fd, buffer, sizeof(buffer));
        write(STDOUT_FILENO, buffer, l);
    }

    close(fd);
}
