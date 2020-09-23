#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
loop: loop.cpp
	$(CC) $(CFLAGS) -o loop loop.cpp

clean:
	rm loop
