.PHONY: _ compile run check doc compile-test test lines clean
_:
	make check; \
	make clean; \
	make compile-test && \
	make test && \
	make compile && \
	echo "Building documentation" && \
	make doc >/dev/null 2>&1 # ignore doxygen, we want tests and compile output

check:
	cppcheck --enable=all --std=c++11 -I src --suppress=missingIncludeSystem src/main.cpp

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/lode src/main.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp src/lib/*.cpp

compile-test:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -o build/test tests/test.cpp src/C.cpp src/inc/*.cpp src/inc/*/*.cpp src/inc/*/*/*.cpp src/lib/*.cpp

run:
	build/lode

test: build/test
	build/test

doc:
	doxygen doxy.conf

lines:
	cat src/* src/**/* 2>/dev/null | wc -l
	cat tests/* tests/**/* 2>/dev/null | wc -l

clean:
	rm -rf build/*
	rm -rf doc/html/

release:
	make clean
	rm -r ditemiku ditemiku.zip; \
	mkdir ditemiku
	cp -r \
			benchmark-ai.sh \
			doc \
			doxy.conf \
			git-version.sh \
			Makefile \
			prohlaseni.txt \
			README \
			src \
			tests \
			zadani.txt \
		ditemiku
	mkdir ditemiku/build
	zip -r ditemiku.zip ditemiku
