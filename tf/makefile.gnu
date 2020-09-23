#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
tf:	main.cpp count.cpp
	$(CC) -Wall -g -o tf main.cpp count.cpp

clean:
	rm tf
