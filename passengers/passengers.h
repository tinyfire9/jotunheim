#include <iostream>
#include <vector>
#include "../utility/passenger/utilityPassenger.cpp"

class PassengerSCH
{
public:
	PassengerSCH();
	void addPassenger(string firstName, string lastName);
private:
	vector<StoragePassenger> storagePassengers;
	vector<NewPassenger> newPassengers;
	PassengerUtility utility;
};