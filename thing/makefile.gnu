#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: thing

thing: thing.cpp
	$(CC) $(CFLAGS) -o thing thing.cpp

clean:
	rm thing
