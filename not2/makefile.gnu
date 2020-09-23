#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: not2

not2: not2.cpp
	$(CC) $(CFLAGS) -o not2 not2.cpp

clean:
	rm not2
