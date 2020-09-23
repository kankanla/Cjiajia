#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: array

array: array.cpp
	$(CC) $(CFLAGS) -o array array.cpp

clean:
	rm array
