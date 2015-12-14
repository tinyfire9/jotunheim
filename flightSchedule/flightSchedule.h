#include <iostream>
#include <vector>
#include "./flight/storageFlight.h"
#include "../utility/flightSchedule/flightScheduleUtility.h"

class FlightSchedule
{
public:
	FlightSchedule();
	/*
	Pre-condition : expects planeId, flight orign, destination, departure date and time, return date and time
	Post-condition : creats a new flight object, 
					adds the new flight object to the current list of flights, 
					updates the current list of flights to on the txt file and 
					flushs the newFlights vector and reload the data form the txt file
	*/
	void addFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime);
	/*
	Pre-condition : expects flightNumber, passengerId, first and last name
	Post-condition : if passenger exits and is not already in,
				it adds the id, first & last name
	*/
	void addPassenger(int flightNumber, int passengerId, string firstName, string lastName);
	/*
	Pre-condition : expects flightNumber, and plane id
	Post-condition : returns true if the flight# and planeId matchs a flight with the given planeId
	*/
	bool flight(int flightNumber, int planeId);
	/*
	Pre-condition : expects flightNumber
	Post-condition : displays all the passengers on the given flightNumber on the console
	*/
	void displayPassengers(int flightNumber);
	// Post-condition : displays all future flights
	void displayUpcomingFlights();
	// Post-condition : displays all past flights
	void displayPastFlights();
	/*
	Pre-condition : expects flightNumber, and plane id
	Post-condition : returns true if the flight# and planeId matchs a flight with the given planeId
	*/
	void changePlane(int flightNumber, int currentPlaneId, int newPlaneId);
private:
	vector<StorageFlight> storageFlights;
	vector<NewFlight> newFlights;
	FlightScheduleUtility utility;
};