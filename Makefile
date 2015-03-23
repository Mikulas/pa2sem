compile: src/hello.cpp
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/hello.cpp
run:
	build/lode
clean:
	rm -rf build/*
