#include "Response.h"

Response Response::from(unsigned char* bytes) {
	uint32_t format;
	memcpy(&format, bytes, sizeof(uint32_t));

	if (format == 0) {
		// simple method invocation
	}
}
