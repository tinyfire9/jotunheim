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
	/*
		Pre-condition : expects flightNumber, current and new plane ID
		Post-condition :
			- checks if current flightNumber exists and planeId is correct && checks if new planeId exists
			- if both exists :
				* if there are enough seats on each class && if the potential seats are all availble
					* change plane on the flightSchedule
					* transfer the passenger from old plane id to the new plane id
	*/
	void transferPassengers(int flightNumber, int currentPlaneId, int newPlaneId);
	/*
		Post-condition : 
			- if the entered planeId exists
				* call add new flight from flight
	*/
	void addNewFlight(	int planeId, 
		string origin, 
		string destination,
		string departureDate,
		string departureTime,
		string returnDate,
		string returnTime);
	// Post-condition : call addPlane from fleet class
	void addNewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows);
	// Post-condition : call addPassenger from flights class
	void addNewPassengerToFlight(int flightNumber, int passengerId, string firstName, string lastName, string seatNumber);
	// Post-condition : call addPassenger from passengers class
	void addNewPassengerToList(string firstName, string lastName);
	// Post-condition : call displayPassengers from passengers class
	void displayPassengers(int flightNumber);
	// Post-condition : call displayUpcomingFlights from flighSchedule class
	void displayUpcomingFlights();
	// Post- condition : call displayPastFlights from flighSchedule class
	void displayPastFlights();
private:
	Fleet fleet;
	PassengerSCH passengers;
	FlightSchedule schedule;
};

#endif