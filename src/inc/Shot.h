#ifndef SHOT
#define SHOT

#include "Location.h"


enum class Response : char {MISS, HIT, SUNK};

class Shot {
public:
	Shot() {};
	Shot(Location location) : location(location) {};
	Location location; // TODO fix visibility
	Response response; // TODO fix visibility
};


#endif
