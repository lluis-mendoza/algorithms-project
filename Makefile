CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -O2
DEPS = Graph.h

.PHONY: all
.DEFAULT: all
all: Graph.o main

Graph.o: Graph.cc Graph.h
	$(CC) $(CFLAGS) -I./ -c Graph.cc

main: Graph.o
	$(CC) $(CFLAGS) -o main main.cc Graph.o

clean:
	rm main *.o
