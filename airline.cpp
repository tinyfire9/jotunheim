#include <iostream>
#include <string>
#include "airline.h"

Airline::Airline(){};

void Airline::transferPassengers(int flightNumber, int planeId1, int planeId2){
	// cout << Airline::fleet.getAvailableFirstClassSeats(27) << endl;
	// Airline::fleet.addPlane(11,22,33,44);
	Airline::fleet.addPassenger(27, 40, "6D");
	// Airline::schedule.addPassenger(22, 333666, "slimfire", "seifu");
}
