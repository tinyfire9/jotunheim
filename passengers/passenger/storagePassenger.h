#include <iostream>
#include <string>
#include "passenger.cpp"
using namespace std;

#ifdef STORAGE_PASSENGER_H
#define STORAGE_PASSENGER_H

class StoragePassenger : public Passenger{
public:
	StoragePassenger(int passengerId, string firstName, string lastName)
	: Passenger(passengerId, firstName, lastName)
	{
		Storage::flightNumber = flightNumber;
	}
	int getFlightNumber();
private:
	int flightNumber;
};

#endif