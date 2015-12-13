#include <iostream>
#include <string>
#include "airline.h"

Airline::Airline(){};

void Airline::transferPassengers(int flightNumber, int currentPlaneId, int newPlaneId){// function to transfer the passengers
	if((Airline::schedule.flight(flightNumber, currentPlaneId) == true) 
		&& ((Airline::fleet.plane(newPlaneId) == true)))
	{
		if(// checks all the available type of seats  if it meets the condition 
			(Airline::fleet.getAvailableFirstClassSeats(currentPlaneId) >= Airline::fleet.getNumberOfFirstClassPassengers(newPlaneId)) &&
			(Airline::fleet.getAvailableEconomyClassSeats(currentPlaneId) >= Airline::fleet.getNumberOfEconomyClassPassengers(newPlaneId)) &&
			(Airline::fleet.getAvailableEconomyPlusClassSeats(currentPlaneId) >= Airline::fleet.getNumberOfEconomyPlusClassPassengers(newPlaneId))
			)
		{
			if(Airline::fleet.allPotentialSeatsAvailable(currentPlaneId, newPlaneId) == true) // if seats are available, do this
			{
				Airline::schedule.changePlane(flightNumber, currentPlaneId, newPlaneId); // change the plane schedule 
				Airline::fleet.transferPassengers(currentPlaneId, newPlaneId); // transfer the passenger from old plane id to the new plane id
			}
			else
			{
				cout << "Sorry, the several seats are already taken! " << endl; // prompt error messages
			}
		}
		else
		{
			cout << "Sorry, there isn't enough amount of seats on the new plane, #" << newPlaneId << endl;
		}
	}
	else
	{
		cout << "The entered flight number, " << flightNumber << "and plane id, " << currentPlaneId << " doesn't match. Please try again!" << endl;
	}
}

void Airline::addNewFlight(int planeId, string origin, string destination,string departureDate,
		string departureTime, string returnDate, string returnTime){
	Airline::schedule.addFlight(planeId, origin, destination,departureDate,
		departureTime, returnDate, returnTime); // function to add new flight 
}

void Airline::addNewPassengerToFlight(int flightNumber, int passengerId, string firstName, string lastName){
	Airline::schedule.addPassenger(flightNumber, passengerId, firstName, lastName); // function to add the new passenger to the flight 
}

void Airline::addNewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows){
	Airline::fleet.addPlane(column, number_of_first_class_rows, number_of_economy_class_rows, number_of_economy_plus_rows);// function to add new plane 
}

void Airline::addNewPassengerToList(string firstName, string lastName){ // add the new passenger to the database list
	Airline::passengers.addPassenger(firstName, lastName);
}

void Airline::displayPassengers(int flightNumber){ // display all the passenger from the given flight number 
	Airline::schedule.displayPassengers(flightNumber);
}

void Airline::displayUpcomingFlights(){ // display all the upcoming flights 
	Airline::schedule.displayUpcomingFlights();
}

int Airline::getMaxId(string type){ // function to get the max id number in the list 
	if(type == "plane")
	{
		return Airline::fleet.getMaxPlaneId();
	}
	else if(type == "passenger")
	{
		return Airline::passengers.getMaxPassengerId();
	}
	else if(type == "flight")
	{
		return Airline::schedule.getMaxFlightId();
	}
	else
	{
		cout << "Entered type does not exist! Available types are plane, passenger and flight. Please try again!" << endl;
	}
}