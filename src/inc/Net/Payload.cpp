#include "Payload.h"


bool Payload::validate() const {
	return crc == CRC::sum(data, length);
}

bool Payload::send(int fd) {
	const uint32_t total = length + sizeof(uint32_t);
	const unsigned char** buffer = (const unsigned char**) malloc(total);
	memcpy(buffer, data, length);
	uint32_t* crc = (uint32_t*) (buffer + length);
	*crc = CRC::sum(data, length);

	write(fd, buffer, total);

	free(buffer);
}
