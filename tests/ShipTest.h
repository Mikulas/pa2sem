#include "TestCase.h"

#include "../src/inc/Location.h"
#include "../src/inc/Ship.h"


class ShipTest : public TestCase {
public:
	virtual void run() override {

		Ship s1(5, "foo");
		assert(s1.setStartEnd(Location(0, 0), Location(0, 0)) == false,
			"zero length");
		assert(s1.setStartEnd(Location(0, 0), Location(s1.length - 1, 0)) == false,
			"lower length x");
		assert(s1.setStartEnd(Location(0, 0), Location(s1.length + 1, 0)) == false,
			"higher length x");
		assert(s1.setStartEnd(Location(0, 0), Location(0, s1.length - 1)) == false,
			"lower length y");
		assert(s1.setStartEnd(Location(0, 0), Location(0, s1.length + 1)) == false,
			"higher length y");
		assert(s1.setStartEnd(Location(0, 0), Location(2, s1.length - 2)) == true,
			"correct length but not in line");
		assert(s1.setStartEnd(Location(0, 0), Location(0, s1.length)) == true,
			"correct length");
	}
};
