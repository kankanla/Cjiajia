#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall

all: bound_err bound_c1 bound_c2

bound_err: bound_err.cpp
	$(CC) -Wall -g -o bound_err bound_err.cpp

bound_c1: bound_c1.cpp
	$(CC) -Wall -g -o bound_c1 bound_c1.cpp

bound_c2: bound_c2.cpp
	$(CC) -Wall -g -o bound_c2 bound_c2.cpp

clean:
	rm bound_err bound_c1 bound_c2
