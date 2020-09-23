#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
class: class.cpp
	$(CC) -Wall -g -o class class.cpp

clean:
	rm class
