#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: array-p

array-p: array-p.cpp
	$(CC) $(CFLAGS) -o array-p array-p.cpp

clean:
	rm array-p
