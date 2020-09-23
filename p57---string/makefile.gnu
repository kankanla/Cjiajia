#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
string: string.cpp
	$(CC) -Wall -g -o string string.cpp

clean:
	rm string
