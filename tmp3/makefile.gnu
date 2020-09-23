#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: tmp3

tmp3: tmp3.cpp
	$(CC) $(CFLAGS) -o tmp3 tmp3.cpp

clean:
	rm tmp3
