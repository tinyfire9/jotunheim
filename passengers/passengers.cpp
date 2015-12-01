#include <iostream>
#include "passengers.h"
#include "./passenger/newPassenger.cpp"

PassengerSCH::PassengerSCH(){
	PassengerSCH::utility.populateReadArray(PassengerSCH::storagePassengers);
}

void PassengerSCH::addPassenger(
	string firstName,
	string lastName
	 ){
	
	NewPassenger passenger(
		firstName,
		lastName
	);
	PassengerSCH::newPassengers.push_back(passenger);
	PassengerSCH::utility.writeFile(PassengerSCH::storagePassengers, PassengerSCH::newPassengers);
}