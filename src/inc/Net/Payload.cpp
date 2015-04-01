#include "Payload.h"

Payload::~Payload() {
	free((char*) this->data);
}

bool Payload::validate() const {
	return crc == CRC::sum(data, length);
}

bool Payload::send(int fd) {
	const uint32_t total = length + sizeof(uint32_t);
	const unsigned char* buffer = (const unsigned char*) malloc(total);
	memcpy((char*)buffer, data, length);
	uint32_t* crc = (uint32_t*) ((char*)buffer + length);
	*crc = CRC::sum(data, length);

	write(fd, (char*)buffer, total);

	free((char*)buffer);
}

/**
 *	- uint32_t type = 0
 *	- char* method
 */
Payload Payload::call(const char* method) {
	const uint32_t type = 0;
	const uint32_t total = sizeof(uint32_t) + strlen(method);
	const unsigned char* buffer = (const unsigned char*) malloc(total);
	memcpy((char*)buffer, &type, sizeof(uint32_t));
	memcpy((char*)buffer + sizeof(uint32_t), method, strlen(method));

	return Payload(buffer, total);
}

/**
 *	- uint32_t type = 0
 *	- Location location
 *	- char* method
 */
Payload Payload::call(const char* method, const Location location) {
	const uint32_t type = 1;
	const uint32_t total = sizeof(uint32_t) + sizeof(Location) + strlen(method);

	const unsigned char* buffer = (const unsigned char*) malloc(total);
	memcpy((char*)buffer, &type, sizeof(uint32_t));
	memcpy((char*)buffer + sizeof(uint32_t), &location, sizeof(Location));
	memcpy((char*)buffer + sizeof(uint32_t) + sizeof(Location), method, strlen(method));

	return Payload(buffer, total);
}
