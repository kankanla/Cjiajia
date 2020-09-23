#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
SRC=ia.cc hist.cc
OBJ=ia.o  hist.o

all: hist
	
hist: $(OBJ)
	$(CC) $(CFLAGS) -o hist $(OBJ)

hist.o: ia.h hist.cc
	$(CC) $(CFLAGS) -c hist.cc

ia.o: ia.h ia.cc
	$(CC) $(CFLAGS) -c ia.cc

clean:
	rm hist io.o hist.o
