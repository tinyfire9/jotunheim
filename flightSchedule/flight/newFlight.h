#include <iostream>
#include <string>
#include "flight.cpp"
#include "../../utility/flightSchedule/flightScheduleUtility.cpp"
using namespace std;

#ifndef NEW_FLIGHT_H
#define NEW_FLIGHT_H

FlightScheduleUtility util;

class NewFlight : public Flight{
public:
	NewFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime)
	: Flight(planeId, origin, destination, departureDate, departureTime, returnDate, returnTime){
		NewFlight::flightNumber = util.generateId();
	}
	int getFlightNumber();
private:
	int flightNumber;
};				

#endif