#include <iostream>
#include "Controller.h"
#include "LineRenderer.h"


using namespace std;

int main(int argc, char **argv)
{
	auto renderer = new LineRenderer;

	Controller controller(renderer);
	controller.run();

	return 0;
}
