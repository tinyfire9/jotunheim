#include <iostream>
#include <string>
#include "../../flightSchedule/flight/newFlight.h"
#include "../utility.h"

#ifndef FLIGHT_UTILITY_H
#define FLIGHT_UTILITY_H

class FlightScheduleUtility : public utility{
	public:
		FlightScheduleUtility(){};
	    void writeFile(vector<StorageFlight> &storageFlights,vector<NewFlight> &newFlights);
	    void populateReadArray(vector<StorageFlight> &flights);
	    void split(string line, vector<string> &words);
	    int stringToInt(string word);
};
#endif