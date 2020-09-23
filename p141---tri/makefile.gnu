#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: tri

tri: tri.cpp
	$(CC) $(CFLAGS) -o tri tri.cpp

clean:
	rm tri
