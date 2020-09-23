#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: perm

perm: perm.cpp
	$(CC) $(CFLAGS) -o perm perm.cpp

clean:
	rm perm
