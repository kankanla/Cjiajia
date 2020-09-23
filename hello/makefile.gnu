#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
hello: hello.cpp
	$(CC) -Wall -g -o hello hello.cpp

clean:
	rm hello
