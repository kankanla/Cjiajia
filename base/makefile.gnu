#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: base base2.o base3.o

base: base.cpp
	$(CC) $(CFLAGS) -o base base.cpp

base2.o: base2.cpp
	@echo "This does not generate a full program"
	$(CC) $(CFLAGS) -c base2.cpp

base3.o: base3.cpp
	@echo "This does not generate a full program"
	$(CC) $(CFLAGS) -c base3.cpp

clean:
	rm base base2.o base3.o
