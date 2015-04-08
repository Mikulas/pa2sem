#include "TestCase.h"

#include "../src/inc/Location.h"
#include "../src/inc/Ship.h"


class ShipTest : public TestCase {
public:
	virtual void run() override {
		Ship s0(5);
		assert(false == s0.isPlaced(),
			"not placed");
		s0.setStartEnd(Location(1, 1), Location(1, s0.length));
		assert(true == s0.isPlaced(),
			"placed");

		Ship s6(2);
		assert(true == s6.setStartEnd(Location(9, 9), Location(9, 8)),
			"placed upside down");

		Ship s1(5, "down");
		Ship s2(5, "right");
		Ship s3(5, "none");
		s1.setStartEnd(Location(1, 1), Location(1, s1.length));
		s2.setStartEnd(Location(1, 1), Location(s2.length, 1));
		s3.setStartEnd(Location(9, 1), Location(9, s3.length));
		assert(true == s1.overlaps(&s2),
			"overlaps");
		assert(false == s1.overlaps(&s3),
			"no overlap x");
		assert(false == s2.overlaps(&s3),
			"no overlap y");


		Ship s4(5);
		assert(false == s4.setStartEnd(Location(1, 1), Location(1, 1)),
			"zero length");
		assert(false == s4.setStartEnd(Location(1, 1), Location(s4.length - 1, 1)),
			"lower length x");
		assert(false == s4.setStartEnd(Location(1, 1), Location(s4.length + 1, 1)),
			"higher length x");
		assert(false == s4.setStartEnd(Location(1, 1), Location(1, s4.length - 1)),
			"lower length y");
		assert(false == s4.setStartEnd(Location(1, 1), Location(1, s4.length + 1)),
			"higher length y");
		assert(false == s4.setStartEnd(Location(1, 1), Location(2, s4.length - 2)),
			"correct length but not in line");
		assert(true == s4.setStartEnd(Location(1, 1), Location(1, s4.length)),
			"correct length");
		// assert(false == s4.setStartEnd(Location(1, 1), Location(1, s4.length)),
		// 	"reset length not allowed");


		Ship s5(2);
		s5.setStartEnd(Location(1, 1), Location(1, s5.length));
		assert(false == s5.isSunk(),
			"not sunk");
		assert(false == s5.hit(Location(9, 9)),
			"not hit");
		assert(true == s5.hit(Location(1, 1)),
			"hit");
		assert(false == s5.isSunk(),
			"not sunk after first hit");
		assert(true == s5.hit(Location(1, 1)),
			"hit on same spot");
		assert(false == s5.isSunk(),
			"not sunk after second hit on same spot");
		assert(true == s5.hit(Location(1, 2)),
			"hit on last spot");
		assert(true == s5.isSunk(),
			"sunk after last hit");
	}
};
