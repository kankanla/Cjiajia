#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: tmp2

tmp2: tmp2.cpp
	$(CC) $(CFLAGS) -o tmp2 tmp2.cpp

clean:
	rm tmp2
