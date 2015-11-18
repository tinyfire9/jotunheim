CXX = g++
CC = g++
CFLAGS = -g

default: flight

flightRes: flight.o
	$(CC) $(CFLAGS) -o flight flight.o 
flight.o: flight.cpp flight.h
	$(CC) $(CFLAGS) -c flight.cpp
