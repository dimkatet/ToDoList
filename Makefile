 CFLAGS = -Wall -Werror
CC = g++
CC = g++ 
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD_SRC = mkdir -p build/src
MKDIR_BUILD_TEST = mkdir -p build/test

.PHONY: clean test

default: bin/Todo.exe
test: bin/test.exe
	$<

bin/test.exe: build/test/main.o build/test/read.o
	mkdir -p bin
	g++ $(CFLAGS) $^ -o $@

build/test/main.o: test/main.cpp thirdparty/testing.hpp src/sdafx.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -std=c++11 -I thirdparty -I src 

build/test/read.o: src/read.cpp src/read.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ)


bin/Todo.exe: build/src/main.o build/src/read.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

build/src/main.o: src/main.cpp src/sdafx.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ)

build/src/read.o: src/read.cpp src/read.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ)

clean:
	rm -rf bin build 