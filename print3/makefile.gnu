#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: print3

print3: print3.cpp
	$(CC) $(CFLAGS) -o print3 print3.cpp

clean:
	rm print3
