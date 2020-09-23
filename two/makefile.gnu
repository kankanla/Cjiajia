#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
two: two.cpp
	$(CC) $(CFLAGS) -o two two.cpp

clean:
	rm two
