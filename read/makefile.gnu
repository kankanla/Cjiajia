#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
read: read.cpp
	$(CC) -Wall -g -o read read.cpp

clean:
	rm read
