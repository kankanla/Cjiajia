#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: die

die: die.cpp
	$(CC) $(CFLAGS) -o die die.cpp

clean:
	rm die
