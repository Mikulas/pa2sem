#include "TestCase.h"

#include <vector>
#include "../src/lib/Arguments.h"

using std::vector;


class ArgumentsTest : public TestCase {
public:
	virtual void run() override {
		vector<char*> args;

		Arguments a1(args.size(), args.data());
		assert(false == a1.flag("flag-a"),
			"flag unset");

		args.push_back("--foo");
		args.push_back("pos1");
		args.push_back("--flag-a");
		args.push_back("--bar");
		Arguments a2(args.size(), args.data());
		assert(true == a2.flag("flag-a"),
			"flag set");

		args.push_back("-v");
		args.push_back("-rf");
		Arguments a3(args.size(), args.data());
		assert(true == a3.flag("_", 'v'),
			"shortcut set single");
		assert(true == a3.flag("_", 'r'),
			"shortcut set double first");
		assert(true == a3.flag("_", 'f'),
			"shortcut set double second");

		args.push_back("pos2");
		Arguments a4(args.size(), args.data());
		auto posvec = a4.getPositional();
		assert(posvec[0] == "pos1",
			"positional first");
		assert(posvec[1] == "pos2",
			"positional second");
	}
};
