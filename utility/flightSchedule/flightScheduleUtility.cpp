#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
#include "../../flightSchedule/flight/storageFlight.cpp"
#include "flightScheduleUtility.h"

using namespace std;

void FlightScheduleUtility::populateReadArray(vector<StorageFlight> &flights)
{
	FlightScheduleUtility util;
	string line = "";
	string chunk = "";
	vector< vector<string> > data;
	fstream readStream;
	readStream.open("../data/flightSchedule.txt");

	//read each line and split by |
	while(getline(readStream, line))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss, chunk, '|') )
		{
			row.push_back(chunk);
		}
		data.push_back(row);
	}
	//(Format) data[i][0] : flightID planeID origin destination depDate depTime retDate retTime
	// on each iteration, 
		// breakdown the flight info part of the data ^ by space & put it in a vector
		// breakdown the passegerInfos (['passID fName lName', 'passID fName lName'] ) by space 
		//		 and push each data on passenger vector

	for (int i = 0; i < data.size(); i++)
	{
		vector<string> chunks;
		vector< vector<string> > passsenger;
		util.split(data[i][0], chunks);

		StorageFlight flight(
			util.stringToInt(chunks[0]), 
			util.stringToInt(chunks[1]), 
			chunks[2], 
			chunks[3],
			chunks[4], 
			chunks[5], 
			chunks[6], 
			chunks[7]
		);
		for (int j = 1; j < data[i].size(); j++)
		{
			vector<string> passsengerInfo;
			util.split(data[i][j], passsengerInfo);
			flight.addPassengerId(util.stringToInt(passsengerInfo[0]));
			flight.addPassengerName(passsengerInfo[1] + " " + passsengerInfo[2]);//lastname, firstname
		}
		flights.push_back(flight);
	}
}


void FlightScheduleUtility::writeFile(vector<StorageFlight> &storageFlights,vector<NewFlight> &newFlights)
{
	// cout << "CHeck YESSSS~!!" << newFlights[0].getOrigin() <<endl;
	string pipe = "|";
	ofstream outputStream;
	string outputData = "";
	outputStream.open("../data/flightSchedule.txt");
	for (int i = 0; i < storageFlights.size(); i++)
	{
		outputStream << storageFlights[i].getFlightNumber() << " " << storageFlights[i].getPlaneId() << " ";
		outputStream << storageFlights[i].getOrigin() << " " << storageFlights[i].getDestination() << " ";
		outputStream << storageFlights[i].getDepartureDate() << " " << storageFlights[i].getDepartureTime() << " ";
		outputStream << storageFlights[i].getReturnDate() << " " << storageFlights[i].getReturnTime();
		vector<int> passengerIds = storageFlights[i].getPassengerIds();
		vector<string> passengerNames = storageFlights[i].getPassengerNames();
		for (int j = 0; j < passengerIds.size(); j++)
		{
			outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerNames[j];
		}
		outputStream << endl;
	}
	for (int i = 0; i < newFlights.size(); i++)
	{
		cout << newFlights[i].getReturnDate() << endl;
		outputStream << newFlights[i].getFlightNumber() << " " << newFlights[i].getPlaneId() << " ";
		outputStream << newFlights[i].getOrigin() << " " << newFlights[i].getDestination() << " ";
		outputStream << newFlights[i].getDepartureDate() << " " << newFlights[i].getDepartureTime() << " ";
		outputStream << newFlights[i].getReturnDate() << " " << newFlights[i].getReturnTime();
		vector<int> passengerIds = newFlights[i].getPassengerIds();
		vector<string> passengerNames = newFlights[i].getPassengerNames();
		for (int j = 0; j < passengerIds.size(); j++)
		{
			outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerNames[j];
		}
		outputStream << endl;
	}
	outputStream.close();
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

int FlightScheduleUtility::stringToInt(string word)
{
	stringstream ss(word);
	int intVersion;
	ss >> intVersion;
	return intVersion;
}