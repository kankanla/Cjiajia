#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: wbin

wbin: wbin.cpp
	$(CC) $(CFLAGS) -o wbin wbin.cpp

clean:
	rm wbin
