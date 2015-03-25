_:
	make compile && make compile-test && make test && make run

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/main.cpp src/inc/*.cpp
run:
	cat stdin | build/lode

compile-test:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp src/inc/*.cpp
test:
	build/test

clean:
	rm -rf build/*
