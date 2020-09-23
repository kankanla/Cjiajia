#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: copy2

copy2: copy2.cpp
	$(CC) $(CFLAGS) -o copy2 copy2.cpp

clean:
	rm copy2
