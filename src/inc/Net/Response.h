#ifndef RESPONSE_H
#define RESPONSE_H

#include <cstdint>
#include <stdio.h>
#include <string.h>


class Response {
public:
	static Response from(unsigned char* bytes);
};


#endif
