#include <iostream>
#include <vector>
#include "../utility/flightSchedule/flightScheduleUtility.cpp"

class FlightSchedule
{
public:
	FlightSchedule();
	void addFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime);
	void addPassenger(int flightNumber, int passengerId, string firstName, string lastName);
private:
	vector<StorageFlight> storageFlights;
	vector<NewFlight> newFlights;
	FlightScheduleUtility utility;
};