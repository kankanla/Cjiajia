#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: calc

calc: calc.cpp
	$(CC) $(CFLAGS) -o calc calc.cpp

clean:
	rm calc
