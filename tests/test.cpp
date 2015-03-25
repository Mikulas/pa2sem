#define _Stringify(x) #x
#define testcase(Class) cout << endl << _Stringify(Class) << endl; (new Class##Test())->run()

#include <iostream>
#include "BoardTest.h"
#include "LocationTest.h"
#include "ShipTest.h"

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
	cout << "\033[1;34m          |\\___..--\"/\033[0m" << endl;
	cout << "\033[1;34m   __..--``        /\033[0m    Battleship test suite" << endl;
	cout << "\033[1;34m  \\_______________/\033[0m" << endl;

	testcase(Location);
	testcase(Ship);
	testcase(Board);

	return 0;
}
