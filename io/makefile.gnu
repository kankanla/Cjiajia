#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: io.out io

io.out: io
	io >io.out

io: io.cpp
	$(CC) $(CFLAGS) -o io io.cpp

clean:
	rm io 
