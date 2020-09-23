#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: copy

copy: copy.cpp
	$(CC) $(CFLAGS) -o copy copy.cpp

clean:
	rm copy
