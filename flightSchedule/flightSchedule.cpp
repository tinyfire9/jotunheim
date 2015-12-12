#include <iostream>
#include <algorithm>
#include <ctime>
#include "flightSchedule.h"
#include "./flight/newFlight.h"


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
	FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");
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
		FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");
	}
}

bool FlightSchedule::flight(int flightNumber, int planeId){
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber && FlightSchedule::storageFlights[i].getPlaneId() == planeId)
		{
			return true;
		}
	}
	return false;
}

void FlightSchedule::displayPassengers(int flightNumber)
{
	bool found = false;
	vector<string> passengers;
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber)
		{
			found = true;
			passengers = FlightSchedule::storageFlights[i].getPassengerNames();
			for (int i = 0; i < passengers.size(); i++)
			{
				cout << passengers[i] << endl;
			}
			break;
		}
	}
	if(!found)
	{
		cout << "Sorry the entered flight number doesn't match any flight! Please try another one! " << endl;
	}
}

void FlightSchedule::displayUpcomingFlights(){
	time_t currentTime;
	struct tm *localTime;
	time( &currentTime );                   // Get the current time
	localTime = localtime( &currentTime );  // Convert the current time to the local time

	int currentYear =  localTime->tm_year + 1900 ;
	int currentMonth = localTime->tm_mon + 1;
	int currentDay = localTime->tm_mday;
	cout << "flightID" << setw(13) << "planeID" << setw(13) << "origin" << setw(13)
	 << "destination" << setw(13) << "depDate" << setw(13) << "depTime" << setw(13) 
	 << "retDate" << setw(13) << "retTime" << endl;
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		string departureDate = FlightSchedule::storageFlights[i].getDepartureDate();
		int month = FlightSchedule::utility.stringToInt(departureDate.substr(0, 2));
		int day = FlightSchedule::utility.stringToInt(departureDate.substr(3,2));
		int year = FlightSchedule::utility.stringToInt(departureDate.substr(6, 4));
		if(year == currentYear)
		{	
			if(month == currentMonth)
			{
				if(day >= currentDay)
				{
					cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
					cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
					cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
					cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
				}
			}
			else if(month > currentMonth)
			{
				cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
				cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
				cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
				cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
			}
		}
		else if(year > currentYear)
		{
			cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
			cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
			cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
			cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
		}
	}
}

int FlightSchedule::getMaxFlightId(){
	int max = 0;
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() > max)
		{
			max = FlightSchedule::storageFlights[i].getFlightNumber();
		}
	}
	return max;
}

void FlightSchedule::changePlane(int flightNumber, int currentPlaneId, int newPlaneId){
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if((FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber) && (FlightSchedule::storageFlights[i].getPlaneId() == currentPlaneId))
		{
			FlightSchedule::storageFlights[i].setPlaneId(newPlaneId);
			FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt");
			FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");
		}
	}

}