#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <cstring>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "../Location.h"
#include "../Ship.h"
#include "../Shot.h"

using std::iostream;
using std::memcpy;
using std::streampos;
using std::string;
using std::stringstream;
using std::strlen;
using std::vector;
using std::runtime_error;

class PayloadException : public runtime_error {
public:
    PayloadException(string const& message)
        : std::runtime_error(message) {}
};

enum class Invoke : uint8_t {Setup = 0xDF, TakeTurn = 0xDE, SaveShot = 0xED};
enum class Field : uint8_t {Location = 0xFF, Shot = 0xFE, Ship = 0xFD, Vector = 0xFC};

class Payload {
public:
	Payload() {}
    Payload(const char* bytes, uint count) {
    	ss.write(bytes, count);

        uint32_t length;
        *this >> length;
        if (length != count) {
            throw PayloadException("Incomplete payload");
        }
    }

	void verify(Field exp) {
		Field load;
    	*this >> load;
    	if (exp != load) {
			throw PayloadException("Failed to validate response node");
    	}
	}

	size_t size() {
		return sizeof(uint32_t) + ss.str().length();
	}

    /**
     * must delete after use
     */
	const char* data() {
        char* buffer = new char[size()];
        uint32_t length = size();
        memcpy(buffer, &length, sizeof(uint32_t));
        memcpy(buffer + sizeof(uint32_t), ss.str().c_str(), size());
		return buffer;
	}

	template<typename T>
	Payload& operator<< (T in) {
		ss.write((const char*) &in, sizeof(T));
		return *this;
	}
    template<typename T>
    Payload& operator>> (T &out) {
		ss.read((char*)&out, sizeof(T));
		return *this;
	}

	Payload& operator<< (string str) {
    	*this << (uint32_t) str.length();
    	ss.write(str.c_str(), str.length());
    	return *this;
    }
    Payload& operator>> (string &val) {
    	uint32_t length;
    	*this >> length;

    	char *buffer = new char[length + 1]();
		ss.read(buffer, length);
    	val = string(buffer);
    	delete buffer;
		return *this;
    }

	Payload& operator<< (Location location) {
    	*this << Field::Location;
    	*this << (uint32_t) location.x;
    	*this << (uint32_t) location.y;
    	return *this;
    }
    Payload& operator>> (Location &val) {
    	verify(Field::Location);
    	*this >> val.x >> val.y;
		return *this;
    }

	Payload& operator<< (Shot shot) {
		*this << Field::Shot;
		*this << shot.location;
		*this << shot.response;
    	return *this;
    }
    Payload& operator>> (Shot &val) {
		verify(Field::Shot);
    	*this >> val.location >> val.response;
		return *this;
    }

    Payload& operator<< (Ship ship) {
    	*this << Field::Ship;
    	*this << ship.name << ship.length << ship.start << ship.end;
    	return *this;
    }
    Payload& operator>> (Ship &val) {
		verify(Field::Ship);
    	*this << Field::Ship;
    	*this >> val.name >> val.length;
    	Location start, end;
    	*this >> start >> end;
    	val.setStartEnd(start, end);
		return *this;
    }

	template<typename T>
    Payload& operator<< (vector<T> vec) {
    	*this << Field::Vector;
    	uint32_t size = vec.size();
    	*this << size;
    	for (auto &item : vec) {
    		*this << item;
    	}
    	return *this;
    }
    template<typename T>
    Payload& operator>> (vector<T> &val) {
    	verify(Field::Vector);
    	uint32_t size;
    	*this >> size;
    	for (int i = 0; i < size; i++) {
    		T item;
    		*this >> item;
    		val.push_back(item);
    	}

		return *this;
    }


	void debug() { // todo remove
		auto str = data();
		printf("payload(%luB): ", size());
		for (int i = 0; i < size(); ++i) {
			printf("%02X ", str[i] & 0xFF);
		}
        delete str;
		printf("\n");
	}

private:
	stringstream ss;
};


#endif
