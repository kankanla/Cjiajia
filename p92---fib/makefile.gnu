#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: fib

fib: fib.cpp
	$(CC) $(CFLAGS) -o fib fib.cpp

clean:
	rm fib
