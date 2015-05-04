#include "Arguments.h"

Arguments::Arguments(int argc, char **argv) {
	for (int i = 0; i < argc; ++i) {
		string partial = argv[i];

		if (partial.compare(0, 2, "--") == 0) {
			// --flag
			flags.insert(partial.substr(2));

		} else if (partial.compare(0, 1, "-") == 0) {
			// -rf == -r -f
			for (int p = partial.length() - 1; p >= 1; --p) {
				shortcuts.insert(partial.at(p));
			}

		} else {
			// foo bar
			positional.push_back(partial);
		}
	}
}

bool Arguments::flag(string flag) {
	return flags.find(flag) != flags.end();
}

bool Arguments::flag(string flag, char shortcut) {
	return flags.find(flag) != flags.end()
		|| shortcuts.find(shortcut) != shortcuts.end();
}

vector<string> Arguments::getPositional() {
	return positional;
}
