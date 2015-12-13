#include <iostream>
#include <vector>
#include "../utility/passenger/utilityPassenger.h"

class PassengerSCH
{
public:
	PassengerSCH();
	void addPassenger(string firstName, string lastName);
	void addFlight(int passengerID, int flightNumber, string seat);
	int getMaxPassengerId();
	bool passenger(int passengerID);
	string getPassengerFirstName(int passengerID);
	string getPassengerLastName(int passengerID);
private:
	vector<StoragePassenger> storagePassengers;
	vector<NewPassenger> newPassengers;
	PassengerUtility utility;
};