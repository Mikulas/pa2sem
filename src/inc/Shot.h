#ifndef SHOT
#define SHOT

#include "Location.h"


/**
 * Wraps Location
 * \see Player::saveShot
 */
class Shot {
public:
	enum class Response : char {MISS, HIT, SUNK};

	Shot() {};
	Shot(Location location) : location(location) {};
	Location location;
	Response response;
};


#endif
