CC=g++
CFLAGS=-Wall -Wextra -O2
DEPS = Graph.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -I

main: Graph.o
	$(CC) $(CFLAGS) -o main main.cc Graph.o

.PHONY: main
clean:
	rm main *.o
