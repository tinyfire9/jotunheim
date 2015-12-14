#include <iostream>
#include <string>
#include "../../flightSchedule/flight/newFlight.h"
#include "../utility.h"

#ifndef FLIGHT_UTILITY_H
#define FLIGHT_UTILITY_H

class FlightScheduleUtility : public utility{
	public:
		//Instansiate class
		FlightScheduleUtility(){};
		/*
			Pre-condition : expects a storageFlight type vector,  a newFlight type vector and a file path
			Post-condition : loops through each item and gets all the data by from each method from both vectors 
					and writes it to a file specified by the user
		*/
	    void writeFile(vector<StorageFlight> &storageFlights,vector<NewFlight> &newFlights, string path);
		/*
			Pre-condition : expects a storageFlight type vector,  and a file path
			Post-condition : loops through each line of the text fil, creating a storageFlight object with the data
					push each object the the vector 
		*/
	    void populateReadArray(vector<StorageFlight> &flights, string path);
	    /*
			Pre-condition : expects a line and a vector 
			Post-condition : splits the line by space and pushes each chunk into the vector
	    */
	    void split(string line, vector<string> &words);
	    /*
			Pre-condition : expects an integer of type string
			Post-condition : return the integer version of the string
	    */
	    int stringToInt(string word);
};
#endif