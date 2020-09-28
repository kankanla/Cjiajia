#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: rec

rec: rec.cpp
	@echo "This compile will generate an error"
	-$(CC) $(CFLAGS) -o rec rec.cpp

clean:
	rm rec
