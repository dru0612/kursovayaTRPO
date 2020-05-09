g = g++
CFLAGS = -c -Wall -Werror

.PHONY: clean run all test

all: bin/source

bin/source: build/src/main.o build/src/source.o
		$(g) $^ -o $@

build/src/main.o: src/main.cpp
		$(g) $(CFLAGS) $^ -o $@

build/src/source.o: src/source.cpp
		$(g) $(CFLAGS) $^ -o $@

GTEST_DIR = thirdparty/googletest

test: testlib bin/source-test

testlib:
	g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
    -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o build/test/gtest-all.o
	ar -rv build/test/libgtest.a build/test/gtest-all.o

bin/source-test: build/test/main.o build/src/source.o
	g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread $^ \
	build/test/libgtest.a -o $@

build/test/main.o:
	$(g) -std=c++11 $(CFLAGS) test/main.cpp -I $(GTEST_DIR)/include -o $@

run:
		bin/source

runtest:
		bin/source-test

clean:
		rm -rf build/src/*.o

cleantest:
		rm build/test/*.o
