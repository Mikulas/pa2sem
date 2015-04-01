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
#include "../Location.h"


class Payload {
public:
	static Payload call(const char* method);
	static Payload call(const char* method, const Location location);

	Payload(const unsigned char* data, uint32_t length) : length(length), data(data) {}
	~Payload();
	bool validate() const;
	bool send(int fd);

private:
	const uint32_t length;
	const unsigned char* data;
	uint32_t crc;
};


#endif
