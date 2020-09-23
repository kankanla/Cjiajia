#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
blow: blow.cpp
	@echo "Newer gcc compilers generate an error for this"
	$(CC) -Wall -g -o blow blow.cpp

clean:
	rm blow
