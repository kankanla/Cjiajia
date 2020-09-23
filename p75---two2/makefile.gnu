#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: twoc

twoc: twoc.cpp
	$(CC) $(CFLAGS) -o twoc twoc.cpp

clean:
	rm twoc
