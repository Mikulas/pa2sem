#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;


class Arguments {
public:
	Arguments(int argc, char **argv);
	bool flag(string flag);
	bool flag(string flag, char shortcut);
	vector<string> getPositional();

private:
	vector<string> positional; // foo bar
	set<char> shortcuts; // -f
	set<string> flags; // --flag
};

#endif
