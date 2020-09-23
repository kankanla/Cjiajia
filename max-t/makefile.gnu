#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: max stack_c1

max: max.cpp
	$(CC) $(CFLAGS) -o max max.cpp

stack_c1: stack_c1.cpp
	$(CC) $(CFLAGS) -o stack_c1 stack_c1.cpp

words: words.cpp
	$(CC) -v $(CFLAGS) -o words words.cpp

words.cpp: words.cc
	$(CC) -E -Wall words.cpp>words.cc

clean:
	rm max stack_c1
