#ifndef NET_PAYLOAD_H
#define NET_PAYLOAD_H

#include <cstring>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "../Location.h"
#include "../Ship.h"
#include "../Shot.h"

using std::iostream;
using std::memcpy;
using std::runtime_error;
using std::streampos;
using std::string;
using std::stringstream;
using std::strlen;
using std::vector;

/**
 * \see Payload
 * \ingroup Net
 */
class PayloadException : public runtime_error {
public:
    PayloadException(string const& message)
        : std::runtime_error(message) {}
};

/**
 * Example usage:
 * \code{.cpp}
 * vector<Ship> ships = ...;
 * Payload p;
 * p << Invoke::Setup
 * p << ships
 * \endcode
 *
 * \code{.cpp}
 * char *data = ...;
 * int length = ...;
 * Payload p(data, length);
 * Invoke i;
 * p >> i;
 * \endcode
 *
 * Invoke format (from Server to Client):
 * \code{.unparsed}
 * uint32_t   total payload length (including this field)
 * Invoke     action
 * ...        additional optional parameters for invoked method:
 *    Field   not necessary but makes sure server and client formats match
 *    data    one or multiple scalars or other fields
 * \endcode
 *
 * Response formats (from Client to Server)
 * \code{.unparsed}
 * uint32_t   total payload length (including this field)
 * Field::Ack empty response (invoke acknowledged)
 * \endcode
 *
 * \code{.unparsed}
 * uint32_t   total payload length (including this field)
 * Field      empty response
 * data       one or multiple scalars or other fields
 * \endcode
 *
 * \ingroup Net
 */
class Payload {
public:
    enum class Invoke : uint8_t {
        Setup = 0xDF, /**< \see Player::setup() */
        TakeTurn = 0xDE, /**< \see Player::takeTurn() */
        SaveShot = 0xDD, /**< \see Player::saveShot() */
        IOAnnounce = 0xDC, /**< \see InOut::announce() */
        IOAnnounceTurn = 0xDB, /**< \see InOut::announceTurn() */
        IOShotResult = 0xDA, /**< \see InOut::renderShotResult() */
        IOGameOver = 0xD9, /**< \see InOut::gameOver() */
    };
    enum class Field : uint8_t {
        Location = 0xFF, /**< \see Location */
        Shot = 0xFE, /**< \see Shot */
        Ship = 0xFD, /**< \see Ship */
        Vector = 0xFC,
        Ack = 0xFB /**< empty response */
    };

	Payload() {}
    Payload(Payload&&) {}

    /**
     * \throws PayloadException if size does not match
     */
    Payload(const char* bytes, uint count) {
        uint32_t expected;
        memcpy(&expected, bytes, sizeof(uint32_t));
        if (expected != count) {
            throw PayloadException("Incomplete payload");
        }

    	ss.write(bytes + sizeof(uint32_t), count - sizeof(uint32_t));
    }

    /**
     * Loads Field, which moves ostream position
     * \throws PayloadException
     */
	void verify(Field exp) {
		Field load;
    	*this >> load;
    	if (exp != load) {
			throw PayloadException("Failed to validate response node");
    	}
	}

    /**
     * \see data()
     */
	size_t size() const {
		return sizeof(uint32_t) + ss.str().length();
	}

    /**
     * Caller must `delete[]` data after use
     * \see size()
     */
	const char* data() const {
        uint32_t length = size();
        char *buffer = new char[length];
        memcpy(buffer, &length, sizeof(uint32_t));
        memcpy(buffer + sizeof(uint32_t), ss.str().c_str(), length - sizeof(uint32_t));
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
    	delete[] buffer;
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

    /**
     * Prints `data()` as hex by bytes
     */
	void debug() {
		const char* buffer = data();
		printf("payload(%uB): ", (uint) size());
		for (uint i = 0; i < size(); ++i) {
			printf("%02X ", buffer[i] & 0xFF);
		}
        delete[] buffer;
		printf("\n");
	}

private:
	stringstream ss;
};


#endif
