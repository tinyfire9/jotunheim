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



void PassengerUtility::populateReadArray(vector<StoragePassenger> &passengers, string path) // function to read array and push back vector data on passenger
{


    PassengerUtility util;
	string line = "";        // initializes the data member to empty
	string chunk = "";       // initializes the data member to empty


	vector< vector<string> >data;
	fstream readStream;
	readStream.open(path.c_str());
	

	while(getline(readStream,line))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss,chunk, '|') ) // data separated by "|"
		{
			row.push_back(chunk); // pushes the chunk into the vector

		}
		data.push_back(row);
         
	}

	for(int i = 0; i < data.size(); i++ )
	{
		vector<string> chunks;
		vector< vector<string> > passenger;
		util.split(data[i][0], chunks);

		StoragePassenger Passenger(
			util.stringToInt(chunks[0]), // convert this id data member to int 
			chunks[1],
			chunks[2]
	    );

	    for(int j = 1; j< data[i].size(); j++) // iterates the data size length
	    {
          vector<string> passengerInfo;
          util.split(data[i][j],passengerInfo);
          Passenger.addFlightNumber(util.stringToInt(passengerInfo[0])); // adds the flight number function 
          Passenger.addPassengerSeat(passengerInfo[1]); // adds the passenger seat info into the data

	    }
	    passengers.push_back(Passenger);
	}

}
	//(Format) data[i][0] : passengerId, firstName, lastName 
	// on each iteration, 
		// breakdown the passenger info part of the data ^ by space & put it in a vector
		// breakdown the passegerInfos (['seatNumber, flightNumber', 'seatNumber, flightNumber'] ) by space 
		//		 and push each data on passenger vector

void PassengerUtility::writeFile(vector<StoragePassenger> &storagePassengers, vector<NewPassenger> &NewPassengers, string path)// function to write to file
{
	string pipe = "|";
	ofstream outputStream;
	string outputData = "";
	// write the data from the storagePassenger and newPassenger to text file
	outputStream.open(path.c_str());
	// extract the data from each method and instert it into the output stream
	for (int i = 0; i< storagePassengers.size(); i++)
	{
		outputStream << storagePassengers[i].getPassengerNumber() << " " << storagePassengers[i].getFirstName() << " ";
		outputStream << storagePassengers[i].getLastName() << " ";
	    vector<int> flightNumbers = storagePassengers[i].getFlightNumber(); // search for the passenger flight number in the storage passenger member function to see if it exist
	    vector<string> passengerSeats = storagePassengers[i].getPassengerSeats();
	    for (int j = 0; j < flightNumbers.size(); j++)
	    {
	    	outputStream << " " << pipe << " " << flightNumbers[j] << " " << passengerSeats[j];
	    }
	    outputStream << endl;

     }
     // extract the data from each method and instert it into the output stream
   for (int i =0 ; i < NewPassengers.size(); i++)
 {

	outputStream << NewPassengers[i].getPassengerNumber() << " " << NewPassengers[i].getFirstName() << " "; 
	outputStream << NewPassengers[i].getLastName() << " ";
  
    vector<int> flightNumbers = NewPassengers[i].getFlightNumber(); // adds the new passenger into flight number vector
    vector<string> passengerSeats = NewPassengers[i].getPassengerSeats();// adds the new passenger seat into the passenger seats vector
    // extract the flightNumbers from each
    for (int j =0; j < flightNumbers.size(); j++)
    {
    	outputStream << " " << pipe << " " << flightNumbers[j] << " " << passengerSeats[i]; // displays the flight number and passenger seats
    }
    outputStream << endl;
  }

  outputStream.close();
}



void PassengerUtility::split(string line, vector<string> &words)// splits the word function 
{
	stringstream ss(line);
	string word = "";
	while(ss >> word)
	{
		words.push_back(word);
	}
}

int PassengerUtility::stringToInt(string word) // convert string to int 
{
	stringstream ss(word);
	int intVersion;
	ss >> intVersion;
	return intVersion;
}

