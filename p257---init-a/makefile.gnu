#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: init-a

init-a: init-a.cpp
	$(CC) $(CFLAGS) -o init-a init-a.cpp

clean:
	rm init-a
