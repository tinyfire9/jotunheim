#include <iostream>
#include <vector>
#include "../utility/flightSchedule/flightScheduleUtility.cpp"

class FlightSchedule
{
public:
	FlightSchedule();
	void addFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime);
	void addPassenger(int flightNumber, int passengerId, string firstName, string lastName);
	bool flight(int flightNumber);
	bool plane(int flightNumber, int planeId);
	void displayPassengers(int flightNumber);
	void displayUpcomingFlights();
private:
	vector<StorageFlight> storageFlights;
	vector<NewFlight> newFlights;
	FlightScheduleUtility utility;
};