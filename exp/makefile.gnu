#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: exp

exp: exp.cpp
	@echo "Expect a null effect warning"
	$(CC) $(CFLAGS) -o exp exp.cpp

clean:
	rm exp
