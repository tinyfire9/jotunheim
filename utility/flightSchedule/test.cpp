#include <iostream>
// #include "../../flightSchedule/flight/newFlight.cpp"
#include "flightScheduleUtility.cpp"

int main(){
	std::vector<StorageFlight> storageFlights;
	std::vector<NewFlight> newFlights;
	FlightScheduleUtility test;
	test.populateReadArray(storageFlights, "asa");
	for (int i = 0; i < storageFlights.size(); i++)
	{
		cout << storageFlights[i].getFlightNumber() << " " << storageFlights[i].getPlaneId() << " " << storageFlights[i].getOrigin() << " " << storageFlights[i].getDestination() << endl;
	}
	test.writeFile(storageFlights, newFlights, "aasd");
	return 0;
}