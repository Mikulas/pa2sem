#include "TestCase.h"

#include "../src/inc/Net/Payload.h"
#include "../src/inc/Location.h"


class PayloadTest : public TestCase {
public:
	virtual void run() override {
		Location input(7, 5);

		Payload p;
		p << input;

		Field field;
		p >> field;
		assert(Field::Location == field,
			"location field");

		Location read;
		p >> read;
		assert(read.x == input.x,
			"location x");
		assert(read.y == input.y,
			"location y");
	}
};
