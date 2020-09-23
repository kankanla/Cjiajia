#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: big

big: big.cpp
	@echo The following compile generates a syntax error
	-$(CC) $(CFLAGS) -o big big.cpp

clean:
	rm big
