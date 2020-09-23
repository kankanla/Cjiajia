#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: tterm

tterm: tterm.cpp
	$(CC) $(CFLAGS) -o tterm tterm.cpp

clean:
	rm tterm
