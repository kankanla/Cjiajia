#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: seven count

count: count.cpp
	$(CC) $(CFLAGS) -o count count.cpp

seven: seven.cpp
	$(CC) $(CFLAGS) -o seven seven.cpp

clean:
	rm seven count
