#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <cstring>
#include <sstream>
#include <iostream>
#include <string>
#include "../Location.h"

using std::strlen;
using std::stringstream;
using std::iostream;
using std::string;
using std::streampos;


enum class Field : uint8_t {Location};

class Payload {
public:
	Payload() {}
    Payload(const char* bytes) {
    	ss.write(bytes, strlen(bytes));
    }

	template<typename T>
	Payload& operator<< (T in) {
		ss.write((const char*) &in, sizeof(T));
		return *this;
	}
    Payload& operator<< (Location location) {
    	*this << Field::Location;
    	*this << (uint32_t) location.x;
    	*this << (uint32_t) location.y;
    	return *this;
    }

    Payload& operator>> (Field &out) {
		ss.read((char*)&out, sizeof(Field));
		return *this;
	}
	Payload& operator>> (uint32_t &out) {
		ss.read((char*)&out, sizeof(uint32_t));
		return *this;
	}
	Payload& operator>> (Location &val) {
    	*this >> val.x >> val.y;
		return *this;
    }

	void debug() { // todo remove
		auto str = ss.str();
		printf("payload(%luB): ", str.length());
		for (int i = 0; i < str.length(); ++i) {
			printf("%02X ", str[i]);
		}
		printf("\n");
	}

private:
	stringstream ss;
};


#endif
