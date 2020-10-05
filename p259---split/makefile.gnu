#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: split

split: split.cpp
	$(CC) $(CFLAGS) -o split split.cpp

clean:
	rm split
