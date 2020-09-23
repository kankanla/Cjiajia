#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
virt: virt.cpp
	$(CC) -Wall -g -o virt virt.cpp

clean:
	rm virt
