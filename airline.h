#include <string>
#include <iostream>
#include "./fleet/fleet.cpp"
#include "./flightSchedule/flightSchedule.cpp"
#include "./passengers/passengers.cpp"

#ifndef AIRLINE
#define AIRLINE

class Airline
{
public:
	Airline();
	void transferPassengers(int flightNumber, int planeId1, int planeId2);
private:
	Fleet fleet;
	PassengerSCH passengers;
	FlightSchedule schedule;
};

#endif