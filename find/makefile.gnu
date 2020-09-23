#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: find.o

find.o: find.cpp
	$(CC) -c $(CFLAGS) find.cpp

clean:
	rm find.o
