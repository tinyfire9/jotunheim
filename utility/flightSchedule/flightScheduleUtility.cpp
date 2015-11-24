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

void FlightScheduleUtility::populateReadArray(/*vector<Flight> &flights, string fileName*/){
	string line = "";
	vector<string> data;
	vector<string> info;
	vector<string> passengers;
	FlightScheduleUtility util;
	fstream readStream;

	readStream.open("../data/flightSchedule.txt");
	while(getline(readStream, line, '|'))
	{
		data.push_back(line);
	}
	util.split(data[0], info);
	for(int i = 1; i < data.size(); i++)
	{
		util.split(data[i], passengers);
	}

}

void FlightScheduleUtility::split(string line, vector<string> &words)
{
	stringstream ss(line);
	string word = "";
	while(ss >> word)
	{
		words.push_back(word);
	}
}