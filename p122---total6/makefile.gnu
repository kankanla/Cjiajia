#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: total6 total6w

total6: total6.cpp
	$(CC) $(CFLAGS) -o total6 total6.cpp

total6w: total6w.cpp
	$(CC) $(CFLAGS) -o total6w total6w.cpp

clean:
	rm total6 total6w
