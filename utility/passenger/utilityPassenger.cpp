/* 
 * File:   utilityPassenger.cpp
 * Author: Silvester
 *
 * Created on November 19, 2015, 9:14 PM
 */
#include <fstream> 
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <string>
#include "../../passengers/passenger/storagePassenger.h"
#include "utilityPassenger.h"
using namespace std;



void PassengerUtility::populateReadArray(vector<StoragePassenger> &passengers, string path)
{


    PassengerUtility util;
	string line = "";
	string chunk = "";


	vector< vector<string> >data;
	fstream readStream;
	readStream.open(path.c_str());
	

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

	for(int i = 0; i < data.size(); i++ )
	{
		vector<string> chunks;
		vector< vector<string> > passenger;
		util.split(data[i][0], chunks);

		StoragePassenger Passenger(
			util.stringToInt(chunks[0]),
			chunks[1],
			chunks[2]
	    );

	    for(int j = 1; j< data[i].size(); j++)
	    {
          vector<string> passengerInfo;
          util.split(data[i][j],passengerInfo);
          Passenger.addFlightNumber(util.stringToInt(passengerInfo[0]));
          Passenger.addPassengerSeat(passengerInfo[1]);

	    }
	    passengers.push_back(Passenger);
	}

}

void PassengerUtility::writeFile(vector<StoragePassenger> &storagePassengers, vector<NewPassenger> &NewPassengers, string path)
{
	string pipe = "|";
	ofstream outputStream;
	string outputData = "";
	outputStream.open(path.c_str());
	for (int i = 0; i< storagePassengers.size(); i++)
	{
		outputStream << storagePassengers[i].getPassengerNumber() << " " << storagePassengers[i].getFirstName() << " ";
		outputStream << storagePassengers[i].getLastName() << " ";
	    vector<int> flightNumbers = storagePassengers[i].getFlightNumber();
	    vector<string> passengerSeats = storagePassengers[i].getPassengerSeats();
	    for (int j = 0; j < flightNumbers.size(); j++)
	    {
	    	outputStream << " " << pipe << " " << flightNumbers[j] << " " << passengerSeats[j];
	    }
	    outputStream << endl;

     }
   for (int i =0 ; i < NewPassengers.size(); i++)
 {
	//cout << NewPlanes[i].get_plane_id() << endl;
	outputStream << NewPassengers[i].getPassengerNumber() << " " << NewPassengers[i].getFirstName() << " ";
	outputStream << NewPassengers[i].getLastName() << " ";
  
    vector<int> flightNumbers = NewPassengers[i].getFlightNumber();
    vector<string> passengerSeats = NewPassengers[i].getPassengerSeats();
    for (int j =0; j < flightNumbers.size(); j++)
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

int PassengerUtility::stringToInt(string word)
{
	stringstream ss(word);
	int intVersion;
	ss >> intVersion;
	return intVersion;
}

