#include "TestCase.h"

#include <string>
#include "../src/inc/Location.h"
#include "../src/inc/Net/Payload.h"
#include "../src/inc/Ship.h"
#include "../src/inc/Shot.h"

using std::string;


class PayloadTest : public TestCase {
public:
	virtual void run() override {
		{
			Payload p;
			string msg = "Payloaded str";
			p << msg;

			string read;
			p >> read;
			assert(read.compare(msg) == 0,
				"string");
		}

		{
			Location input(7, 5);

			Payload p;
			p << input;

			Location read;
			p >> read;
			assert(read.x == input.x,
				"location x");
			assert(read.y == input.y,
				"location y");
		}

		{
			Location input(7, 5);
			Payload p;
			Shot shot(input);
			shot.response = Response::HIT;
			p << shot;

			Shot readShot;
			p >> readShot;
			assert(readShot.location == shot.location,
				"shot location");
			assert(readShot.response == shot.response,
				"shot response");
		}

		{
			Payload p;
			Ship ship(5, "Destroyer");
			ship.setStartEnd(Location(3, 2), Location(3, 2+ship.length));
			p << ship;

			Ship readShip;
			p >> readShip;
			assert(readShip.length == ship.length,
				"ship length");
			assert(readShip.name.compare(ship.name) == 0,
				"ship name");
			assert(readShip.start == ship.start,
				"ship start");
			assert(readShip.end == ship.end,
				"ship end");
		}

		{
			Payload p;
			vector<Location> locs;
			locs.push_back(Location(0, 1));
			locs.push_back(Location(3, 4));
			locs.push_back(Location(4, 1));
			p << locs;

			vector<Location> read;
			p >> read;
			assert(locs.size() == read.size(),
				"vector item count");
			assert(locs.at(0) == read.at(0),
				"vector item 0");
			assert(locs.at(1) == read.at(1),
				"vector item 1");
			assert(locs.at(2) == read.at(2),
				"vector item 2");
		}
	}
};
