#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: sqr-i

sqr-i: sqr-i.cpp
	$(CC) $(CFLAGS) -o sqr-i sqr-i.cpp

clean:
	rm sqr-i
