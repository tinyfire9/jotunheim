#include <iostream>
#include <algorithm>
#include "flightSchedule.h"
#include "./flight/newFlight.cpp"

FlightSchedule::FlightSchedule(){
	FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");
}

void FlightSchedule::addFlight(
	int planeId, 
	string origin, 
	string destination,
	string departureDate,
	string departureTime,
	string returnDate,
	string returnTime ){
	
	NewFlight flight(
		planeId,
		origin,
		destination,
		departureDate,
		departureTime,
		returnDate,
		returnTime
	);
	FlightSchedule::newFlights.push_back(flight);
	FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt");
}

void FlightSchedule::addPassenger(int flightNumber, int passengerId, string firstName, string lastName){
	bool found = false;
	bool duplicatePassenger = false;
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber)
		{
			found = true;
			std::vector<int> ids = FlightSchedule::storageFlights[i].getPassengerIds();
			for (int j = 0; j < ids.size(); j++)
			{
				if(ids[j] == passengerId)
				{
					duplicatePassenger = true;
				}
			}
		}
		if((duplicatePassenger == false) && (found == true))
		{
			FlightSchedule::storageFlights[i].addPassengerId(passengerId);
			FlightSchedule::storageFlights[i].addPassengerName(firstName + " " + lastName);
			break;
		}
	}
	// for (int i = 0; i < newFlights.size(); i++)
	// {
	// 	std::vector<int> ids = FlightSchedule::newFlights[i].getPassengerIds();
	// 	for (int j = 0; j < ids.size(); j++)
	// 	{
	// 		cout << ids[j] << " == " << passengerId << " :: " << duplicatePassenger<< endl;
	// 		if(ids[j] == passengerId)
	// 		{
	// 			duplicatePassenger = true;
	// 		}
	// 	}
	// 	if(FlightSchedule::newFlights[i].getFlightNumber() == flightNumber && duplicatePassenger)
	// 	{
	// 		FlightSchedule::newFlights[i].addPassengerId(passengerId);
	// 		FlightSchedule::newFlights[i].addPassengerName(firstName + " " + lastName);
	// 		found = true;
	// 	}
	// }

	if(found == false)
	{
		cout << "Entered flight number, " << flightNumber << ", does not exist! Please try again!" << endl;
	}
	else if(duplicatePassenger == true)
	{
		cout << "Passenger " << firstName << " " << lastName << ", with Id #" << passengerId << " is already in the flight !" << endl;
	}
	else
	{
		FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt");
	}
}

// @TODO make it account newFlights ?
bool FlightSchedule::flight(int flightNumber){
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber)
		{
			return true;
		}
	}
	return false;
}

bool FlightSchedule::plane(int flightNumber, int planeId){
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber && FlightSchedule::storageFlights[i].getPlaneId() == planeId)
		{
			return true;
		}
	}
	return false;
}