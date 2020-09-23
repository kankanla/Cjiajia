#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: good bad

good: good.cpp
	$(CC) $(CFLAGS) -o good good.cpp

bad: bad.cpp
	$(CC) $(CFLAGS) -o bad bad.cpp

clean:
	rm good bad
