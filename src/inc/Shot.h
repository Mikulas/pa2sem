#include "Location.h"

enum class Response : char {MISS, HIT, SUNK};

class Shot {
public:
	Shot(Location location) : location(location) {};
	Location location;
	Response response;
};
