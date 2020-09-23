#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: sam

sam: sam.cpp
	$(CC) $(CFLAGS) -o sam sam.cpp

clean:
	rm sam
