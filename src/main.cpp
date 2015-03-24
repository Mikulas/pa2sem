#include <iostream>
#include "Controller.h"
#include "LineInOut.h"


using namespace std;

int main(int argc, char **argv)
{
	auto renderer = new LineInOut;

	Controller controller(renderer);
	controller.run();

	return 0;
}
