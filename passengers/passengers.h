#include <iostream>
#include <vector>
#include "../utility/passenger/utilityPassenger.h"

class PassengerSCH
{
public:
	PassengerSCH();
	/*
	Pre-condition : expects passengerID, firstName, lastName and seat
	Post-condition : creates a new passenger object,
	                               addes the new passenger object to the current list of passengers,
	                               updates the current list of passengers to the txt file and
	                               flushs the newPassenger vector and reload the data from the text file
	*/
	void addPassenger(string firstName, string lastName);
	/*
	Pre-condition : expects firstName, and lastname 
	Post-condition : returns true if the passenger first name and last name matches the passenger list
	*/
	void addFlight(int passengerID, int flightNumber, string seat);
	/*
	Pre-condition : expects passengerID, flightNumber, and seat 
	Post-condition : if passenger exits and is not already in,
				it adds the id, first & last name
	*/
	int getMaxPassengerId();
	bool passenger(int passengerID);
	/*
	Pre-condition : expects passengerID
	Post-condition : displays the passengers on the given passenger ID on the console.
	*/
	string getPassengerFirstName(int passengerID);
	string getPassengerLastName(int passengerID);
private:
	vector<StoragePassenger> storagePassengers;
	vector<NewPassenger> newPassengers;
	PassengerUtility utility;
};