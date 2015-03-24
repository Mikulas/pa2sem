#include "TestCase.h"

#include "../src/inc/Location.h"
#include "../src/inc/Ship.h"


class ShipTest : public TestCase {
public:
	virtual void run() override {

		Ship s1(5, "foo");
		assert(false == s1.setStartEnd(Location(0, 0), Location(0, 0)),
			"zero length");
		assert(false == s1.setStartEnd(Location(0, 0), Location(s1.length - 1, 0)),
			"lower length x");
		assert(false == s1.setStartEnd(Location(0, 0), Location(s1.length + 1, 0)),
			"higher length x");
		assert(false == s1.setStartEnd(Location(0, 0), Location(0, s1.length - 1)),
			"lower length y");
		assert(false == s1.setStartEnd(Location(0, 0), Location(0, s1.length + 1)),
			"higher length y");
		assert(false == s1.setStartEnd(Location(0, 0), Location(2, s1.length - 2)),
			"correct length but not in line");
		assert(true == s1.setStartEnd(Location(0, 0), Location(0, s1.length)),
			"correct length");
		assert(false == s1.setStartEnd(Location(0, 0), Location(0, s1.length)),
			"reset length not allowed");
	}
};
