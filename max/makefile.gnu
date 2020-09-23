#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: max

max: max.cpp
	@echo "This compile generates a warning"
	$(CC) $(CFLAGS) -o max max.cpp

clean:
	rm max
