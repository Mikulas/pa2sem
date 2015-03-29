#include <stdlib.h>
#include <time.h>
#include "inc/Controller.h"
#include "inc/LineInOut.h"


using namespace std;

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */
int main(int argc, char **argv)
{
	srand(time(NULL));

	auto renderer = new LineInOut;

	Controller controller(renderer);
	controller.run();

	return 0;
}
