#include <iostream>
#include <vector>
#include "./flight/storageFlight.h"
#include "../utility/flightSchedule/flightScheduleUtility.h"

class FlightSchedule
{
public:
	FlightSchedule();
	void addFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime);
	void addPassenger(int flightNumber, int passengerId, string firstName, string lastName);
	bool flight(int flightNumber, int planeId);
	void displayPassengers(int flightNumber);
	void displayUpcomingFlights();
	int getMaxFlightId();
	void changePlane(int flightNumber, int currentPlaneId, int newPlaneId);
private:
	vector<StorageFlight> storageFlights;
	vector<NewFlight> newFlights;
	FlightScheduleUtility utility;
};