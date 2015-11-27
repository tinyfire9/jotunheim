#include <iostream>
#include <string>
// #include "../../flightSchedule/flight/newFlight.h"
#include "../utility.h"

#ifndef FLIGHT_UTILITY_H
#define FLIGHT_UTILITY_H

class FlightScheduleUtility : public utility{
	public:
		FlightScheduleUtility(){};
		int generateId(/*vector<Flight> &flights*/);
	    void writeFile(vector<StorageFlight> &storageFlights,vector<NewFlight> &newFlights, string filename);
	    void populateReadArray(vector<StorageFlight> &flights, string filename);
	    void split(string line, vector<string> &words);
	    int stringToInt(string word);
};
#endif