#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: total

total: total.cpp
	$(CC) $(CFLAGS) -o total total.cpp

clean:
	rm total
