#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: and

and: and.cpp
	$(CC) $(CFLAGS) -o and and.cpp

clean:
	rm and
