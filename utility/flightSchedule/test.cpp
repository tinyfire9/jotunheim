#include <iostream>
#include "../../flightSchedule/flight/newFlight.cpp"
#include "flightScheduleUtility.cpp"

int main(){
	std::vector<StorageFlight> storageFlights;
	std::vector<NewFlight> newFlights;
	FlightScheduleUtility test;
	test.populateReadArray(storageFlights);
	NewFlight test2(10, "DFWW", "JFK","nov.10","10:00am","nov12","9:00pm");
	test2.addPassengerId(1234);
	test2.addPassengerName("yohannes seifu");

	test2.addPassengerId(5678);
	test2.addPassengerName("yoho zel");
	
	newFlights.push_back(test2);
	test.writeFile(storageFlights, newFlights);

	NewFlight test3(15, "SFO", "JFK","dec.22","10:00am","dec23","03:00am");
	test3.addPassengerId(1234);
	test3.addPassengerName("yohannes seifu");

	test3.addPassengerId(5678);
	test3.addPassengerName("yoho zel");

	newFlights.push_back(test3);
	// cout << storageFlights[5].getReturnDate() <<  storageFlights[5].getReturnDate() << endl;
	test.writeFile(storageFlights, newFlights);
	return 0;
}