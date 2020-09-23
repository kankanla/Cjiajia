#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: calc3

calc3: calc3.cpp
	$(CC) $(CFLAGS) -o calc3 calc3.cpp

clean:
	rm calc3
