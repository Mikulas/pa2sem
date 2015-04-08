.PHONY: _ compile run doc compile-test test lines clean
_:
	make compile-test && make test && make compile # && make run

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/main.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
run:
	build/lode

run-ai:
	build/lode < examples/ai2-vs-ai2 | grep -v " turn" | grep -v "miss"

doc:
	doxygen doxy.conf

compile-test:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
test:
	build/test

lines:
	cat src/* src/**/* 2>/dev/null | wc -l
	cat tests/* tests/**/* 2>/dev/null | wc -l

clean:
	rm -rf build/*
	rm -rf doc/*
