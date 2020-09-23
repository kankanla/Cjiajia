#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: xgets.o xgets2.o

xgets.o: xgets.cpp
	@echo "The following does not generate a full program"
	$(CC) -c $(CFLAGS) xgets.cpp

xgets2.o: xgets2.cpp
	@echo "The following does not generate a full program"
	$(CC) -c $(CFLAGS) xgets2.cpp

clean:
	rm xgets.o xgets2.o
