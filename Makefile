CC=gcc
CFLAGS=-c -Wall

all: bytecheck

bytecheck: bytecheck.o
	$(CC) bytecheck.o -o bytecheck

bytecheck.o: bytecheck.c
	$(CC) $(CFLAGS) bytecheck.c

clean:
	rm -rf *o main
