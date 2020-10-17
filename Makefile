CC=g++
CFLAGS=-Wall -Wextra -O2

main: 
	$(CC) $(CFLAGS) -o main main.cc

.PHONY: main
clean:
	rm main
