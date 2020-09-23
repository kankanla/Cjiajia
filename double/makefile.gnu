#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: double

double: double.cpp
	$(CC) $(CFLAGS) -o double double.cpp

clean:
	rm double
