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

void FlightScheduleUtility::populateReadArray(vector<Flight> &flights, string filename)
{
	FlightScheduleUtility util;
	string line = "";
	string chunk = "";
	vector< vector<string> > data;
	fstream readStream;
	readStream.open("../data/flightSchedule.txt");

	//read each line and split by |
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
	for (int i = 0; i < data.size(); i++)
	{
		vector<string> chunks;
		vector< vector<string> > passsenger;
		util.split(data[i][0], chunks);
		for (int j = 1; j < ; j++)
		{
			vector<string> passsengerInfo;
			util.split(data[i][j], passsengerInfo);
			passsenger.push_back(passsengerInfo);
		}
		
		// @TODO
		// structure the data using flight classes
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
