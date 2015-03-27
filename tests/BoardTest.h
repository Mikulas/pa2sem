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

		assert(nullptr == b0.isShipAt(Location(9, 9)),
			"isShipAt empty");
		assert(nullptr != b0.isShipAt(Location(1, 1)),
			"isShipAt ok");

		assert(nullptr == b0.hit(Location(9, 9)),
			"hit empty");
		assert(nullptr != b0.hit(Location(1, 1)),
			"hit first ok");
		assert(nullptr != b0.hit(Location(1, s0.length)),
			"hit last ok");


        Board b1;
        Ship s1(5);
		s1.setStartEnd(Location(0, 0), Location(0, 4));
        b1.ships.push_back(s1);
        Ship s2(4);
		s2.setStartEnd(Location(1, 0), Location(1, 3));
        b1.ships.push_back(s2);
        Ship s3(3);
		s3.setStartEnd(Location(2, 0), Location(2, 2));
        b1.ships.push_back(s3);
        Ship s4(3);
		s4.setStartEnd(Location(3, 0), Location(3, 2));
        b1.ships.push_back(s4);
        Ship s5(2);
		s5.setStartEnd(Location(4, 0), Location(4, 1));
        b1.ships.push_back(s5);
        assert(nullptr != b1.hit(Location(4, 0)),
			"hit end ok");
		assert(nullptr != b1.hit(Location(4, 1)),
			"hit end ok");
		assert(nullptr == b1.hit(Location(4, 2)),
			"hit end ok");
	}
};
