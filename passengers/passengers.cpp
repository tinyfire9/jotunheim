#include <iostream>
#include "passengers.h"
#include "./passenger/newPassenger.h"
#include <algorithm>

PassengerSCH::PassengerSCH(){
	PassengerSCH::utility.populateReadArray(PassengerSCH::storagePassengers,"./utility/data/passenger.txt");
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
	PassengerSCH::utility.writeFile(PassengerSCH::storagePassengers, PassengerSCH::newPassengers,"./utility/data/passenger.txt");
}
void PassengerSCH::addFlight(int passengerID, int flightNumber, string seat){
	bool found = false;
	bool duplicateFlightNumber = false;
	bool duplicateSeat = false;
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		if(PassengerSCH::storagePassengers[i].getPassengerNumber() == passengerID)
		{
			found = true;
			vector<int> ids = PassengerSCH::storagePassengers[i].getFlightNumber();
			vector<string> seatNumbers = PassengerSCH::storagePassengers[i].getPassengerSeats();
			for (int j = 0; j < ids.size(); j++)
			{
				if(ids[j] == flightNumber)
				{
					duplicateFlightNumber = true;
				}
			}
			for (int j = 0; j < seatNumbers.size(); j++)
			{
				if(seatNumbers[j] == seat)
				{
					duplicateSeat = true;
				}
			}
		}
		if((duplicateFlightNumber == false) && (duplicateSeat == false) && (found == true))
		{
			PassengerSCH::storagePassengers[i].addFlightNumber(flightNumber);
			PassengerSCH::storagePassengers[i].addPassengerSeat(seat);
		}
	}

	
	if(found == false)
	{
		cout << "Entered passenger number, " << passengerID << ", does not exist! Please try again!" << endl;
	}
	if(duplicateFlightNumber == true)
	{
		cout << "Flight number " << flightNumber << ", with seat number " << seat << " is already taken in the flight !" << endl;
	}
	if(duplicateSeat == true)
	{
		cout << "Seat number " << seat << ", with passenger Id " << flightNumber << " is already taken in the flight !" << endl;
	}
	else
	{
		PassengerSCH::utility.writeFile(PassengerSCH::storagePassengers, PassengerSCH::newPassengers, "./utility/data/passenger.txt");
	}
    
}

int PassengerSCH::getMaxPassengerId(){
	int max = 0;
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		if(PassengerSCH::storagePassengers[i].getPassengerNumber() > max)
		{
			max = PassengerSCH::storagePassengers[i].getPassengerNumber();
		}
	}
	return max;
}