#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: search0 search1 search2 search3 search4

search0: search0.cpp
	$(CC) -Wall -g -o search0 search0.cpp

search1: search1.cpp
	$(CC) -Wall -g -o search1 search1.cpp

search2: search2.cpp
	$(CC) -Wall -g -o search2 search2.cpp

search3: search3.cpp
	$(CC) -Wall -g -o search3 search3.cpp

search4: search4.cpp
	$(CC) -Wall -g -o search4 search4.cpp


clean:
	rm search0 search1 search2 search3 search4
