#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <cstdlib.h>
#include "../../passengers/passenger/storagePassenger.cpp"
#include "../passengerUtility.h"
using namespace std;

 void PassengerUtility::populateReadArray(vector<StoragePassenger> &passengers)
 {
	PassengerUtility util;
	string line = "";
	string chunk = "";

	vector< vector<string> > data;
	fstream readStream;
	readStream.open("../data/passenger.txt");

	while(getline(readStream,line))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss,chunk, '|') )
		{
			row.push_back(chunk);

		}
		data.push_back(row);
	}

	for(int i = 0; i < data.size(); i++)
	{
		vector<string> chunks;
		vector< vector<string> > passenger;
		util.split(data[i][0],chunks);

		StoragePassenger Passenger(
			util.stringToInt(chunks[0]),
			chunks[1],
			chunks[2]
			);

		for(int j = 1; j< data[i].size();j++)
		{
			vector<string> passengerInfo;
			util.split(data[i][j],passengerInfo);
			Passenger.addPassengerSeat(passengerInfo[0]);
			Passenger.addFlightNumber(util.stringToInt(passengerInfo[1]);
		}
		passengers.push_back(Passenger);
	}
 }

void PassengerUtility::writeFile(vector<StoragePassenger> &storagePassengers, vector<NewPassenger> &NewPassengers)
{
	string pipe = "|";
	ofstream outputStream;
	string outputStream = "";
	outputStream.open("../data/passenger.txt");
	for(int i =0 ; i<storagePassengers.size(); i++)
	{
		outputStream << storagePassengers[i].getPassengerId() << " " << storagePassengers[i].getFirstName() << " ";
		outputStream << storagePassengers[i].getLastName();
		vector<int> flightNumbers = storagePassengers[i].getFlightNumber();
		vector<string> passengerSeats = storagePassengers[i].getPassengerSeats();
		for (int j =0 ; j<flightNumbers.size(); j++)
		{
			outputStream << " " << pipe << " " << flightNumbers << " " << passengerSeats[i];
		}
		outputStream << endl;
	}

	for(int i = 0; i <NewPassengers.size(); i++)
	{
		cout << NewPassengers[i].getPassengerId() << endl;
		outputStream << NewPassengers[i].getPassengerId() << " " << NewPassengers[i].getFirstName() << " ";
		outputStream << NewPassengers[i].getLastName() << " ";
		vector<int> flightNumbers = NewPassengers[i].getFlightNumber();
		vector<string> passengerSeats = NewPassengers[i].getPassengerSeats();
		for(int j = 0; j < flightNumbers.size(); j++)
		{
			outputStream << " " << pipe << " " << flightNumbers[j] << " " << passengerSeats[i];
		}
		outputStream << endl;
	}

	outputStream.close();
}

 void PassengerUtility::split(string line, vector<string> &words)
 {
 	stringstream ss(line);
 	string word = "";
 	while(ss >> word)
 	{
 		words.push_back(word);
 	}
 }

 void PassengerUtility::stringToInt(string word)
 {
 	stringstream ss(word);
 	int intVersion;
 	ss >> intVersion;
 	return intVersion;
 }