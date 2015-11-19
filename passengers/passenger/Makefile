CXX = g++
CC = g++
CFLAGS = -g

default: passenger

passenger: passenger.o
	$(CC) $(CFLAGS) -o passenger passenger.o 
passenger.o: passenger.cpp passenger.h
	$(CC) $(CFLAGS) -c passenger.cpp
