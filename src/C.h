#ifndef CONSOLECOLOR
#define CONSOLECOLOR

#include <string>

using std::string;


/**
 * Utility class for outputing console colors
 * C stands for Color
 *
 * Expects support for ANSI escape codes.
 *
 * Colors override each other.
 * Multiple effects may be applied at once.
 *
 * \code{.cpp}
 * cout << C::green << C::bold << "Huge success" << C::reset << endl;
 * \endcode
 */
class C {
public:
	static const string reset;

	static const string bold;  /**< Effect */
	static const string underline;  /**< Effect */

	static const string red;  /**< Color */
	static const string green;  /**< Color */
	static const string yellow;  /**< Color */
	static const string blue;  /**< Color */
	static const string magenta;  /**< Color */
	static const string cyan;  /**< Color */
};

#endif
