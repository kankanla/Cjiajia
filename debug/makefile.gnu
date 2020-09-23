#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: flush cstop.o flush2

flush: flush.cpp
	$(CC) -Wall -o flush flush.cpp

flush2: flush2.cpp
	$(CC) -Wall -o flush2 flush2.cpp

cstop.o: cstop.cpp
	@echo "Generates object file only"
	$(CC) -Wall -c cstop.cpp

clean:
	rm flush cstop.o flush2
