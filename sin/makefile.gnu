#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
sine: sine.cpp
	$(CC) $(CFLAGS) -o sine sine.cpp -lm

clean:
	rm sine
