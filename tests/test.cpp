#define _Stringify(x) #x
#define testcase(Class) cout << endl << _Stringify(Class) << endl; (new Class##Test())->run()

#include <iostream>
#include "../src/C.h"
// #include "BoardTest.h"
// #include "LocationTest.h"
// #include "ShipTest.h"
#include "PayloadTest.h"

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
	cout << C::bold << C::blue
		<< "          |\\___..--\"/" << C::reset << endl;
	cout << C::bold << C::blue
		<< "   __..--``        /" << C::reset
		<< "  Battleship test suite" << endl;
	cout << C::bold << C::blue
		<< "  \\_______________/" << C::reset << endl;

	// testcase(Location);
	// testcase(Ship);
	// testcase(Board);
	testcase(Payload);

	cout << endl << C::bold << C::green << "All " << TestCase::countPassed() << " tests passed" << C::reset << endl;

	return 0;
}
