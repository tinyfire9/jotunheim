#include <iostream>
#include <string>
#include "passenger.h"
using namespace std;

#ifndef STORAGE_PASSENGER_H
#define STORAGE_PASSENGER_H

class StoragePassenger : public Passenger{
public:
	StoragePassenger(int passengerId, string firstName, string lastName) // a class that stores the passenger id, first name and last name
	: Passenger(firstName, lastName)
	{
		StoragePassenger::passengerId =  passengerId;
	}
	int getPassengerNumber(); // function to get the passenger number 
private:
	int passengerId;


};				

#endif