#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: words

words: words.cpp
	$(CC) $(CFLAGS) -o words words.cpp

clean:
	rm words
