CFLAGS = -Wall -Werror
CC = g++
.PHONY: clean test

all:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/main src/main.cpp 
	
clean:
	rm -rf bin build