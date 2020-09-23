#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: sqr

sqr: sqr.cpp
	$(CC) $(CFLAGS) -o sqr sqr.cpp

clean:
	rm sqr
