#include <iostream>
#include "inc/Controller.h"
#include "inc/LineInOut.h"


using namespace std;

int main(int argc, char **argv)
{
	auto renderer = new LineInOut;

	Controller controller(renderer);
	controller.run();

	return 0;
}
