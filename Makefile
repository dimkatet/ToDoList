CFLAGS = -Wall -Werror
CC = g++
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD_SRC = mkdir -p build/src
MKDIR_BUILD_TEST = mkdir -p build/test

.PHONY: clean test

default: bin/Todo.exe
test: bin/test.exe
	$<

bin/test.exe: build/test/main.o build/test/write.o build/test/read.o build/test/edit.o build/test/score.o
	mkdir -p bin
	g++ $(CFLAGS) $^ -o $@ -L thirdparty/SFML/lib -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lopenal32 -lfreetype -lopengl32 -lwinmm -lgdi32

build/test/main.o: test/main.cpp thirdparty/testing.hpp src/sdafx.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -std=c++11 -I thirdparty -I src  -g -DSFML_STATIC -I thirdparty/SFML/include

build/test/write.o: src/write.cpp src/write.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/test/read.o: src/read.cpp src/read.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/test/edit.o: src/edit.cpp src/edit.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/test/score.o: src/score.cpp src/score.hpp
	$(MKDIR_BUILD_TEST)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

bin/Todo.exe: build/src/main.o build/src/write.o build/src/read.o build/src/edit.o build/src/score.o build/src/checkclisk.o build/src/interface.o
	mkdir -p bin
	g++ $(CFLAGS) $^ -o $@ -L thirdparty/SFML/lib -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lopenal32 -lfreetype -lopengl32 -lwinmm -lgdi32

build/src/main.o: src/main.cpp src/sdafx.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/src/write.o: src/write.cpp src/write.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include


build/src/read.o: src/read.cpp src/read.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/src/edit.o: src/edit.cpp src/edit.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include


build/src/score.o: src/score.cpp src/score.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ)  -g -DSFML_STATIC -I thirdparty/SFML/include

build/src/checkclisk.o: src/checkclisk.cpp src/checkclisk.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include

build/src/interface.o: src/interface.cpp src/interface.hpp
	$(MKDIR_BUILD_SRC)
	$(OBJ) -g -DSFML_STATIC -I thirdparty/SFML/include	

clean:
	rm -rf bin build 