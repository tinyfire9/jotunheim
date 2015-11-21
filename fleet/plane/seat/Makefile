CXX = g++
CC = g++
CFLAGS = -g

default: flightRes

flightRes: seat.o firstClassSeat.o economyClassSeat.o economyPlusClassSeat.o
	$(CC) $(CFLAGS) -o flightRes seat.o firstClassSeat.o economyClassSeat.o economyPlusClassSeat.o
seat.o: seat.cc seat.h
	$(CC) $(CFLAGS) -c seat.cc
firstClassSeat.o: firstClassSeat.cc firstClassSeat.h
	$(CC) $(CFLAGS) -c firstClassSeat.cc
economyClassSeat.o:economyClassSeat.cc economyClassSeat.h
	$(CC) $(CFLAGS) -c economyClassSeat.cc
economyPlusClassSeat.o:economyPlusClassSeat.cc economyPlusClassSeat.h
	$(CC) $(CFLAGS) -c economyPlusClassSeat.cc