#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "../CRC.h"
#include "../Location.h"

class PayloadException {};


class Payload {
public:
	static Payload call(const char* method);
	static Payload call(const char* method, const Location location);
	static Payload read(const unsigned char* bytes);

	Payload(const unsigned char* data, uint32_t length) : length(length), data(data), crc(0) {}
	Payload(const unsigned char* data, uint32_t length, uint32_t crc) : length(length), data(data), crc(crc) {}
	~Payload();
	bool validate() const;
	bool send(int fd);

	const uint32_t length;
	const unsigned char* data;
	const uint32_t crc;
};


#endif
