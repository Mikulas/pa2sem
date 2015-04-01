#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <cctype>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "../CRC.h"


class Payload {
public:
	uint32_t length;
	unsigned char* data;
	uint32_t crc;
	bool validate() const;
	bool send(int fd);
};


#endif
