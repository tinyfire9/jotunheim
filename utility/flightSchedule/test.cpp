#include <iostream>
// #include ""
#include "flightScheduleUtility.cpp"

int main(){
	std::vector<StorageFlight> flights;
	FlightScheduleUtility test;
	test.populateReadArray(flights, "asa");
	for (int i = 0; i < flights.size(); i++)
	{
		cout << flights[i].getFlightNumber() << " " << flights[i].getPlaneId() << " " << flights[i].getOrigin() << " " << flights[i].getDestination() << endl;
	}
	return 0;
}