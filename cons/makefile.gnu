#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
class.o: class.cpp
	@echo "This does not generate a full program"
	$(CC) -Wall -g -c class.cpp

clean:
	rm class.o
