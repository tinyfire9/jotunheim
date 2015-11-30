#include <iostream>
#include <string>
#include "passenger.cpp"
using namespace std;

#ifdef STORAGE_PASSENGER_H
#define STORAGE_PASSENGER_H

class StoragePassenger : public Passenger{
public:
	StoragePassenger(int passengerId, string firstName, string lastName, string seatNumber, int flightNumber)
	: Passenger(passengerId, firstName, lastName, seatNumber, flightNumber ){
		Storage::flightNumber = flightNumber;
	}
	int getFlightNumber();
private:
	int flightNumber;
};

#endif