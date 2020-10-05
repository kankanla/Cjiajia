#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: stack_c stack_d1.o stackex1

stack_d1.o: stack_d1.cpp
	$(CC) $(CFLAGS) -c stack_d1.cpp

stackex1: stackex1.cpp
	-$(CC) $(CFLAGS) -o stackex1 stackex1.cpp

stack_c: stack_c.cpp
	$(CC) $(CFLAGS) -o stack_c stack_c.cpp

clean:
	rm stack_c stack_d1.o stackex1
