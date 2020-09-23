#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: cent

cent: cent.cpp
	$(CC) $(CFLAGS) -o cent cent.cpp

clean:
	rm cent

