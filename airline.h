#include <string>
#include <iostream>
#include "./fleet/fleet.cpp"
#include "./flightSchedule/flightSchedule.cpp"
#include "./passengers/passengers.cpp"

#ifndef AIRLINE
#define AIRLINE

class Airline
{
public:
	Airline();
	void transferPassengers(int flightNumber, int currentPlaneId, int newPlaneId);
	void addFlight(	int planeId, 
		string origin, 
		string destination,
		string departureDate,
		string departureTime,
		string returnDate,
		string returnTime);
	void addNewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows);
	void addNewPassengerToFlight(int flightNumber, int passengerId, string firstName, string lastName);
	void addNewPassengerToList(string firstName, string lastName);
private:
	Fleet fleet;
	PassengerSCH passengers;
	FlightSchedule schedule;
};

#endif