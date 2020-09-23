#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
ref: ref.cpp
	@echo "This compile will generate a warning"
	$(CC) -Wall -g -o ref ref.cpp

clean:
	rm ref
