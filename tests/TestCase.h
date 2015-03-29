#ifndef TESTCASE
#define TESTCASE

#define assertExc(lambda, msg) _assertExc([]() lambda, msg)

#include <exception>
#include <iostream>
#include <string>
#include "../src/C.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;


class TestCase {
public:
	virtual ~TestCase() {};
	virtual void run() = 0;
	static unsigned int countPassed() {
		return passed;
	}

protected:
	template<typename T> void assert(T val) {
		assert(val, "");
	}
	template<typename T> void assert(T val, string msg) {
		if (!val) {
			cerr << C::bold << C::red << "- [ ] " << msg << C::reset << endl;
			exit(1);
		} else if (msg.size()) {
			cout << C::green << "- [x] " << C::reset << msg << endl;
		}
		passed++;
	}
	template<typename T> void _assertExc(T lambda, string msg) {
		bool caught = false;
		try {
			lambda();
		} catch (...) {
			caught = true;
		}
		assert(caught, msg);
		passed++;
	}

private:
	static unsigned int passed;
};

unsigned int TestCase::passed = 0;


#endif
