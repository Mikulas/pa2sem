#include <iostream>
#include "LocationTest.h"
#include "ShipTest.h"

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
	cout << "\033[1;34m          |\\___..--\"/\033[0m" << endl;
	cout << "\033[1;34m   __..--``        /\033[0m    Battleship test suite" << endl;
	cout << "\033[1;34m  \\_______________/\033[0m" << endl;

	cout << endl << "Location" << endl;
	(new LocationTest())->run();

	cout << endl << "Ship" << endl;
	(new ShipTest())->run();

	return 0;
}
