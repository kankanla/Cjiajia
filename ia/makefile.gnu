#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
SRC=ia.cpp hist.cc
OBJ=ia.o  hist.o

all: hist
	
hist: $(OBJ)
	$(CC) $(CFLAGS) -o hist $(OBJ)

hist.o: ia.h hist.cpp
	$(CC) $(CFLAGS) -c hist.cpp

ia.o: ia.h ia.cpp
	$(CC) $(CFLAGS) -c ia.cpp

clean:
	rm hist io.o hist.o
