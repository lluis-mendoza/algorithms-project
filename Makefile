CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -O2
DEPS = Graph.h

.PHONY: all
.DEFAULT: all
all: Graph.o Graph2D.o modeloC modeloD

Graph.o: Graph.cc Graph.h
	$(CC) $(CFLAGS) -I./ -c Graph.cc

modeloC: Graph.o .FORCE
	$(CC) $(CFLAGS) -o modeloC modeloC.cc Graph.o

Graph2D.o: Graph2D.cc Graph2D.h
	$(CC) $(CFLAGS) -I./ -c Graph2D.cc

modeloD: Graph2D.o .FORCE
	$(CC) $(CFLAGS) -o modeloD modeloD.cc Graph2D.o

.FORCE:
clean:
	rm modeloD modeloC *.o
