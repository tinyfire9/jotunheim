#include <iostream>
#include <string>
#include "flight.cpp"
#include <sstream>
#include <fstream>
using namespace std;

#ifndef NEW_FLIGHT_H
#define NEW_FLIGHT_H

class NewFlight : public Flight{
public:
	NewFlight(int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime)
	: Flight(planeId, origin, destination, departureDate, departureTime, returnDate, returnTime){
		string line = "";
		int max = 0;
		int id = 0;
		fstream readStream;
		readStream.open("./utility/data/flightSchedule.txt");
		while(getline(readStream, line))
		{
			stringstream ss(line);
			ss >> id;
			if(id > max)
			{
				max = id;
			}
		}
		readStream.close();
		NewFlight::flightNumber = max + 1;
	}
	int getFlightNumber();
private:
	int flightNumber;
};				

#endif