#include <iostream>
#include <string>
#include <fstream>
#include "flightScheduleUtility.h"

int FlightScheduleUtility::generateId(vector<Flight> &flights){
	int maximum = 0;
	for(int i = 0; i < flights.size(); i++)
	{
		if(flights[i].getId() > maximum)
		{
			maximum = flights[i].getId();
		}
	}
	return maximum;
}

void FlightScheduleUtility::populateReadArray(vector<Flight> &flights, string fileName){
	string data = "";
	fstream readStream;
	readStream.open("../data/flightSchedule.txt");
	getline(readStream, data);
	// cout << "----> " << data << endl;
}
