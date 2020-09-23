#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: first first.out

first: first.cpp
	$(CC) $(CFLAGS) -o first first.cpp

first.out: first.cpp
	$(CC) -E -Wall first.cpp >first.out

clean:
	rm first.out first
