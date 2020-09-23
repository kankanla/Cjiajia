#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: float1

float1: float1.cpp
	@echo "This program will generate a warning when compiled"
	$(CC) $(CFLAGS) -o float1 float1.cpp

clean:
	rm float1
