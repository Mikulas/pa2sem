compile: src/hello.cpp
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/hello.cpp
run:
	build/lode

compile-tests: tests/test.cpp
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp
test:
	build/test

clean:
	rm -rf build/*
