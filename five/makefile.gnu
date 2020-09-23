#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: five

five: five.cpp
	$(CC) $(CFLAGS) -o five five.cpp

clean:
	rm five
