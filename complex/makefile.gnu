#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
complex.o: complex.cpp complex.h
	@echo "Early versions of the gnu compiler generate errors"
	$(CC) -Wall -g -c complex.cpp

clean:
	rm complex.o
