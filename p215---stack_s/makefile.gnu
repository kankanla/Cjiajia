#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
stack_s: stack_s.cpp
	$(CC) $(CFLAGS) -o stack_s stack_s.cpp

clean:
	rm stack_s
