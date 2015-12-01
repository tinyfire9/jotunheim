#include <iostream>
#include <string>
#include "passenger.cpp"
using namespace std;

#ifndef STORAGE_PASSENGER_H
#define STORAGE_PASSENGER_H

class StoragePassenger : public Passenger{
public:
	StoragePassenger(int passengerId, string firstName, string lastName)
	: Passenger(firstName, lastName)
	{
		StoragePassenger::passengerId =  passengerId;
	}
	int getPassengerNumber();
private:
	int passengerId;


};				

#endif