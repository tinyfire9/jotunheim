#include <iostream>
#include <string>
#include "flight.h"
#include <sstream>
#include <fstream>
using namespace std;

#ifndef NEW_FLIGHT_H
#define NEW_FLIGHT_H

class NewFlight : public Flight{
public:
	NewFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime)
	: Flight(planeId, origin, destination, departureDate, departureTime, returnDate, returnTime){ // new flight function when added
		string line = ""; // set line to empty
		int max = 0;
		int id = 0;
		fstream readStream;
		readStream.open("./utility/data/flightSchedule.txt"); // open and reads the flight schedule file text
		while(getline(readStream, line))
		{
			stringstream ss(line);
			ss >> id;
			if(id > max)
			{
				max = id;
			}
		}
		readStream.close(); // close file 
		NewFlight::flightNumber = max + 1; // increment flight number by 1 from the last flight number 
	}
	int getFlightNumber(); // get flight number function
private:
	int flightNumber;
};				

#endif