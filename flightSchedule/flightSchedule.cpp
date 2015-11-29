#include <iostream>
#include "flightSchedule.h"
#include "./flight/newFlight.cpp"

FlightSchedule::FlightSchedule(){
	FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights);
}

void FlightSchedule::addFlight(
	int planeId, 
	string origin, 
	string destination,
	string departureDate,
	string departureTime,
	string returnDate,
	string returnTime ){
	
	NewFlight flight(
		planeId,
		origin,
		destination,
		departureDate,
		departureTime,
		returnDate,
		returnTime
	);
	FlightSchedule::newFlights.push_back(flight);
	// cout << FlightSchedule::newFlights[1].getFlightNumber() << " -- yoyo " << FlightSchedule::storageFlights.size() << FlightSchedule::newFlights.size() << endl;
	FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights);
}