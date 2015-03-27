#ifndef CONSOLECOLOR
#define CONSOLECOLOR

#include <string>

using std::string;


/** C for Color */
class C {
public:
	static const string reset;

	static const string bold;
	static const string underline;

	static const string red;
	static const string green;
	static const string yellow;
	static const string blue;
	static const string magenta;
	static const string cyan;
};

#endif
