CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -O2
DEPS = Graph.h

.PHONY: all
.DEFAULT: all
all: Graph.o modeloC modeloD

Graph.o: Graph.cc Graph.h
	$(CC) $(CFLAGS) -I./ -c Graph.cc

modeloC: Graph.o .FORCE
	$(CC) $(CFLAGS) -o modeloC modeloC.cc Graph.o

modeloD: Graph.o .FORCE
	$(CC) $(CFLAGS) -o modeloD modeloD.cc Graph.o

.FORCE:
clean:
	rm modeloD modeloC *.o
