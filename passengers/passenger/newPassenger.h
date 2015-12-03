#include <iostream>
#include <string>
#include "passenger.cpp"
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
		int max = 0;
		int id = 0;
		fstream readStream;
		readStream.open("./utility/data/passenger.txt");
		while(getline(readStream,line))
		{
			stringstream ss(line);
			ss >> id;
			if(id > max)
			{
				max = id;
			}
		}
		NewPassenger::passengerNumber = max + 1;

	}

	int getPassengerNumber();

private:
	int passengerNumber;
};
#endif
