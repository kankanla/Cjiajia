#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: fixed_test

fixed_test:: fixed_pt.o fixed_test.o

fixed_test.o: fixed_test.cpp fixed_pt.h
	@echo "Early versions of the gnu compiler generate errors"
	$(CC) -Wall -g -c fixed_test.cpp

fixed_pt.o: fixed_pt.cpp fixed_pt.h
	@echo "Early versions of the gnu compiler generate errors"
	$(CC) -Wall -g -c fixed_pt.cpp

clean:
	rm *.o fixed_test
