#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: graph

graph: graph.cpp
	$(CC) $(CFLAGS) -o graph graph.cpp

clean:
	rm graph
