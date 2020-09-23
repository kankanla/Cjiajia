#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: print

print: print.cpp
	$(CC) $(CFLAGS) -o print print.cpp

clean:
	rm print
