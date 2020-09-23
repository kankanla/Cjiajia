#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: comment

comment: comment.cpp
	@echo "This program will not compile due to an error"
	-$(CC) $(CFLAGS) -o comment comment.cpp

clean:
	rm comment
