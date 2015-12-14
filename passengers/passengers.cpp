#include <iostream>
#include "passengers.h"
#include "./passenger/newPassenger.h"
#include <algorithm>

PassengerSCH::PassengerSCH(){
	PassengerSCH::utility.populateReadArray(PassengerSCH::storagePassengers,"./utility/data/passenger.txt"); // gets the data from the passenger utility
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
	PassengerSCH::utility.writeFile(PassengerSCH::storagePassengers, PassengerSCH::newPassengers,"./utility/data/passenger.txt"); // write to the passenger utility text file
}
void PassengerSCH::addFlight(int passengerID, int flightNumber, string seat){
	bool found = false;
	bool duplicateFlightNumber = false;
	bool duplicateSeat = false;
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		/*
	        iterates through each passengers checks if flight Number exist
	 	       -if it finds the passenger Number
			       - check if the passenger is already in the flight
		       -if the flightNumber is found and the passenger is not already in there
			       - add passenger and it's name
			       - write to txt file
			       -fluse newPassenger vector and reload data to storagePassenger vector
	*/		if(PassengerSCH::storagePassengers[i].getPassengerNumber() == passengerID)
		{
			/*
			if passenger number is found, 
				- add the flight to passenger
				- write to file
				- flush newPassenger vector & re-load data to storagePassengers vector
		    */
			found = true;
			vector<int> ids = PassengerSCH::storagePassengers[i].getFlightNumber();
			vector<string> seatNumbers = PassengerSCH::storagePassengers[i].getPassengerSeats();
			for (int j = 0; j < ids.size(); j++)
			{
				if(ids[j] == flightNumber)
				{
					duplicateFlightNumber = true; // checks if there is duplication of flight number
				}
			}
			for (int j = 0; j < seatNumbers.size(); j++)
			{
				if(seatNumbers[j] == seat)
				{
					duplicateSeat = true; // checks the seat number size and duplicate seat
				}
			}
		}
		if((duplicateFlightNumber == false) && (duplicateSeat == false) && (found == true))
		{
			PassengerSCH::storagePassengers[i].addFlightNumber(flightNumber); // adds the new flight number into storage
			PassengerSCH::storagePassengers[i].addPassengerSeat(seat); // adds the new passenger seat into strage
			break;
		}
	}

	
	if(found == false) // check conditions if flight, seat or passenger number is taken or exist.
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
	/*
		for each passenger, it gets the flight number and seat number
			- compares the flight number, seat number and passenger number
			   displays if the seat number or passenger has already taken the flight in the future
	*/
    
}

int PassengerSCH::getMaxPassengerId(){ // gets the max passenger id to check the capacity of passenger intake
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

bool PassengerSCH::passenger(int passengerID){
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		if(PassengerSCH::storagePassengers[i].getPassengerNumber() == passengerID)
		{
			return true;
		}
	}
	return false;
}

string PassengerSCH::getPassengerFirstName(int passengerID){
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		if(PassengerSCH::storagePassengers[i].getPassengerNumber() == passengerID)
		{
			return PassengerSCH::storagePassengers[i].getFirstName();
		}
	}
}

string PassengerSCH::getPassengerLastName(int passengerID){
	for (int i = 0; i < PassengerSCH::storagePassengers.size(); i++)
	{
		if(PassengerSCH::storagePassengers[i].getPassengerNumber() == passengerID)
		{
			return PassengerSCH::storagePassengers[i].getLastName();
		}
	}
}