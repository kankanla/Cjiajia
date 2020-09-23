#
# Makefile for the Free Software Foundations g++ compiler
#
C_COMPILE=gcc
CFLAGS=-g -Wall
fun-file: fun-file.cpp
	$(C_COMPILE) $(CFLAGS) -o fun-file fun-file.cpp

clean:
	rm fun-file
