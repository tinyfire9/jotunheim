#include <iostream>
#include <string>
#include "../../flightSchedule/flight/flight.cpp"
#include "../utility.h"

#ifndef FLIGHT_UTILITY_H
#define FLIGHT_UTILITY_H

class FlightScheduleUtility : public utility{
	public:
		FlightScheduleUtility();
		int generateId(vector<Flight> &flights);
	    void writeFile(vector<Flight> &flights,string filename);
	    void populateReadArray(vector<Flight> &flights, string filename);
};
#endif