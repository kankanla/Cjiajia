#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: value ref big.o

big.o: big.cpp
	$(CC) -Wall -g -c big.cpp

value: value.cpp
	$(CC) -Wall -g -o value value.cpp

ref: ref.cpp
	$(CC) -Wall -g -o ref ref.cpp

clean:
	rm big.o value ref
	
