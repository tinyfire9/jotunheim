#include <string>
#include <iostream>
#include "./fleet/fleet.h"
#include "./flightSchedule/flightSchedule.h"
#include "./passengers/passengers.h"

#ifndef AIRLINE
#define AIRLINE

class Airline
{
public:
	Airline();
	void transferPassengers(int flightNumber, int currentPlaneId, int newPlaneId);
	void addNewFlight(	int planeId, 
		string origin, 
		string destination,
		string departureDate,
		string departureTime,
		string returnDate,
		string returnTime);
	void addNewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows);
	void addNewPassengerToFlight(int flightNumber, int passengerId, string firstName, string lastName, string seatNumber);
	void addNewPassengerToList(string firstName, string lastName);
	void displayPassengers(int flightNumber);
	void displayUpcomingFlights();
	void displayPastFlights();
	int getMaxId(string type);
private:
	Fleet fleet;
	PassengerSCH passengers;
	FlightSchedule schedule;
};

#endif