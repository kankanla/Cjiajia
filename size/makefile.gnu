#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: size

size: size.cpp
	$(CC) $(CFLAGS) -o size size.cpp

clean:
	rm size
