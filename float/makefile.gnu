#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: float

float: float.cpp
	$(CC) $(CFLAGS) -o float float.cpp

clean:
	rm float
