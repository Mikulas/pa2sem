#include "TestCase.h"

#include "../src/inc/Board.h"
#include "../src/inc/Location.h"


class BoardTest : public TestCase {
public:
	virtual void run() override {

		Board b0;
		Ship s0(5);
		assert(false == b0.canPlace(&s0),
			"canPlace no coords");
		s0.setStartEnd(Location(1, 1), Location(1, s0.length));
		assert(true == b0.canPlace(&s0),
			"canPlace ok");

		b0.ships.push_back(s0);

		assert(false == b0.canPlace(&s0),
			"canPlace overlap");
	}
};
