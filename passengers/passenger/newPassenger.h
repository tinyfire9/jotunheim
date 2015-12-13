#include <iostream>
#include <string>
#include "passenger.h"
#include <sstream>
#include <fstream>
using namespace std;

#ifndef NEW_PASSENGER_H
#define NEW_PASSENGER_H

class NewPassenger : public Passenger{
public:
	NewPassenger(string firstName, string lastName )
	: Passenger(firstName, lastName ){
		string line = "";
		int max = 0;     // initialize max passenger to increment whenever passenger is added to 0
		int id = 0;  // initialize passenger if to 0
		fstream readStream;
		readStream.open("./utility/data/passenger.txt"); // open the passenger text file and read it
		while(getline(readStream,line))
		{
			stringstream ss(line); // read on each line and convert to string stream
			ss >> id;
			if(id > max)
			{
				max = id;
			}
		}
		NewPassenger::passengerNumber = max + 1; // increment the passenger number by 1 from the last passenger in the list when adding new passenger

	}

	int getPassengerNumber(); // function to get the 

private:
	int passengerNumber;
};
#endif
