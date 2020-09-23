#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: def

def: def.cpp
	$(CC) $(CFLAGS) -o def def.cpp

clean:
	rm def
