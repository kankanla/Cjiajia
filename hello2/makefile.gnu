#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
hello2: hello2.cpp
	$(CC) -Wall -g -o hello2 hello2.cpp

clean:
	rm hello2
