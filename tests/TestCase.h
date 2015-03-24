#ifndef TESTCASE
#define TESTCASE

#define assertExc(lambda, msg) _assertExc([]() lambda, msg)

#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;


class TestCase {
public:
	virtual ~TestCase() {};
	virtual void run() = 0;

protected:
	template<typename T> void assert(T val) {
		assert(val, "");
	}
	template<typename T> void assert(T val, string msg) {
		if (!val) {
			cerr << "\033[1;31m- [ ] \033[31m" << msg << "\033[0m" << endl;
			exit(1);
		} else if (msg.size()) {
			cout << "\033[32m- [x] \033[0m" << msg << endl;
		}
	}
	template<typename T> void _assertExc(T lambda, string msg) {
		bool caught = false;
		try {
			lambda();
		} catch (exception* e) {
			caught = true;
		}
		assert(caught, msg);
	}
};


#endif
