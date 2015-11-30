#include <iostream>
#include <string>
#include "../../passengers/passenger/newPassenger.h"
#include "../utility.h"

#ifndef PASSENGER_UTILITY_H
#define PASSENGER_UTILITY_H

class PassengerUtility : public utility{
public:
	PassengerUtility(){};
	void writeFile(vector<StoragePassenger> &storagePassengers, vector<NewPassenger> &newPassengers);
	void populateReadArray(vector<StoragePassenger> &passengers);
	void split(string line, vector<string> &words);
	void stringToInt(string word);
};

#endif
