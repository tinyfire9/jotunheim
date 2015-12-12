#include <iostream>
#include <string>
#include "flight.h"
using namespace std;

#ifndef STORAGE_FLIGHT_H
#define STORAGE_FLIGHT_H

class StorageFlight : public Flight{
public:
	StorageFlight(int flightNumber, int planeId, string origin, string destination,string departureDate,string departureTime,string returnDate,string returnTime)
	: Flight(planeId, origin, destination, departureDate, departureTime, returnDate, returnTime){
		StorageFlight::flightNumber = flightNumber;
	}
	int getFlightNumber();
private:
	int flightNumber;
};				

#endif