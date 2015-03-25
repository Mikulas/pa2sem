#include "TestCase.h"

#include "../src/inc/Game.h"
#include "../src/inc/Location.h"


class LocationTest : public TestCase {
public:
	virtual void run() override {

		assertExc({Location invalid(BOARD_SIZE, 0);},
			"out of bound coords throw x");
		assertExc({Location invalid(0, BOARD_SIZE);},
			"out of bound coords throw y");


		Location zero(0, 0);
		Location zero2(0, 0);
		assert(true == (zero == zero2),
			"operator == positive");
		assert(false == (zero == Location(1, 1)),
			"operator == negative");
		assert(true == (zero != Location(1, 1)),
			"operator != positive");
		assert(false == (zero != zero2),
			"operator != negative");


		assert(1 == zero.distance(&zero),
			"distance self");
		assert(5 == Location(4, 0).distance(&zero),
			"distance x");
		assert(5 == Location(0, 4).distance(&zero),
			"distance y");
		assert(6 == Location(2, 3).distance(&zero),
			"distance mixed");

		assert(false == Location(1, 1).inLine(&zero),
			"inLine diagonal");
		assert(true == Location(1, 0).inLine(&zero),
			"inLine x");
		assert(true == Location(0, 1).inLine(&zero),
			"inLine y");
	}
};
