.PHONY: _ compile run doc compile-test test lines clean
_:
	make compile && make compile-test && make test # && make run

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/main.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
run:
	#cat stdin | build/lode
	build/lode

doc:
	doxygen doxy.conf

compile-test:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp
unit:
	build/test
cept:
	bash tests/cept/run.sh
test:
	make unit && make cept

lines:
	cat src/* src/**/* 2>/dev/null | wc -l
	cat tests/* tests/**/* 2>/dev/null | wc -l

clean:
	rm -rf build/*
	rm -rf doc/*
