# ******************************(****
# Control Variables
CC = g++
CFLAGS =i -g -Wall

# ***********************************
# Targets
main: main.o point.o square.o
	$(CC) $(CFLAGS) =-o main main.o point.o square.o

main.o:main.cpp point.h square.h
	$(CC) $(CFLAGS) -c main.cpp
Point.o: Point.h

Square.o: Square.h Point.h
