#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: length.o rlen.o

length.o: length.cpp
	@echo "Warning, this generates an object file only"
	@echo "This compile generates a warning message"
	$(CC) -c $(CFLAGS) length.cpp

rlen.o: rlen.cpp
	@echo "Warning, this generates an object file only"
	$(CC) -c $(CFLAGS) rlen.cpp

clean:
	rm length.o rlen.o
