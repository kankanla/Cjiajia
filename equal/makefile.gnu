#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
equal: equal.cpp
	$(CC) -Wall -g -o equal equal.cpp

clean:
	rm equal
