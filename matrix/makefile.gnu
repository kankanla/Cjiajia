#
# Makefile for the Free Software Foundations g++ compiler
#
CC=g++
CFLAGS=-g -Wall
all: matrix1.o matrix2.o matrix3.o matrix4.o \
     matrix5.o matrix6.o matrix7.o matrix8.o matrix9.o

matrix1.o:matrix1.cpp
	@echo "These commands generate object files only"
	$(CC) $(CFLAGS) -c matrix1.cpp
 
matrix2.o:matrix2.cpp
	$(CC) $(CFLAGS) -c matrix2.cpp
 
matrix3.o:matrix3.cpp
	$(CC) $(CFLAGS) -c matrix3.cpp
 
matrix4.o:matrix4.cpp
	$(CC) $(CFLAGS) -c matrix4.cpp
 
matrix5.o:matrix5.cpp
	$(CC) $(CFLAGS) -c matrix5.cpp
 
matrix6.o:matrix6.cpp
	$(CC) $(CFLAGS) -c matrix6.cpp
 
matrix7.o:matrix7.cpp
	$(CC) $(CFLAGS) -c matrix7.cpp
 
matrix8.o:matrix8.cpp
	@echo "The following compile generates a warning"
	$(CC) $(CFLAGS) -c matrix8.cpp
 
matrix9.o:matrix9.cpp
	@echo "The following compile generates a warning"
	$(CC) $(CFLAGS) -c matrix9.cpp

clean:
	rm matrix?.o
