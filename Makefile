CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -O2
DEPS = Graph.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -I

main: Graph.o
	$(CC) $(CFLAGS) -o main main.cc Graph.o

.PHONY: main
clean:
	rm main *.o
