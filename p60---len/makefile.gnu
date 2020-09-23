#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: len

len: len.cpp
	$(CC) $(CFLAGS) -o len len.cpp

clean:
	rm len
