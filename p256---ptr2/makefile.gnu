#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: ptr2 ptr2a

ptr2a: ptr2a.cpp
	$(CC) $(CFLAGS) -o ptr2a ptr2a.cpp

ptr2: ptr2.cpp
	$(CC) $(CFLAGS) -o ptr2 ptr2.cpp

clean:
	rm ptr2 ptr2a
