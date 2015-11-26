#include <iostream>
#include <string>
#include <sstream>
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

void FlightScheduleUtility::populateReadArray()
{
	string line = "";
	string chunk = "";
	vector< vector<string> > data;
	fstream readStream;
	readStream.open("../data/flightSchedule.txt");

	while(getline(readStream, line, '\n'))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss, chunk, '|'))
		{
			row.push_back(chunk);
		}
		data.push_back(row);
	}
}