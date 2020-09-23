#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: tmp-name

tmp-name: tmp-name.cpp
	$(CC) $(CFLAGS) -o tmp-name tmp-name.cpp

clean:
	rm tmp-name
