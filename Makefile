.PHONY: _ compile run doc compile-test test lines clean
_:
	make check && make compile-test && make test && make compile # && make run

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/main.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
run:
	build/lode

check:
	cppcheck --enable=all --std=c++11 -I src --suppress=missingIncludeSystem src/main.cpp

run-ai:
	build/lode < examples/ai2-vs-ai2 | grep -v " turn" | grep -v "miss"

doc:
	doxygen doxy.conf

compile-test:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
test:
	build/test

man:
	ln -s `pwd`/doc/lode.1 /usr/share/man/man1/lode.1

lines:
	cat src/* src/**/* 2>/dev/null | wc -l
	cat tests/* tests/**/* 2>/dev/null | wc -l

clean:
	rm -rf build/*
	rm -rf doc/*
