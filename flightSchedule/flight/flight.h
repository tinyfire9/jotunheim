#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	@TODO
		* document each method
*/

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight
{
	public:
		Flight(
			int planeId,
			string origin, 
			string destination,
			string departureDate,
			string departureTime,
			string returnDate,
			string returnTime
		);
		int getPlaneId();
		int getFlightNumber();
		string getOrigin(); 
		string getDestination(); 
		string getDepartureDate(); 
		string getDepartureTime();
		string getReturnDate(); 
		string getReturnTime();
		vector<int> getPassengerIds();
		vector<string> getPassengerNames();
		void setPlaneId(int planeId);
		void setOrigin(string origin); 
		void setDestination(string destination); 
		void setDepartureDate(string departureDate); 
		void setDepartureTime(string departureTime);
		void setReturnDate(string returnDate); 
		void setReturnTime(string returnTime);
		void addPassengerId(int passengerId);
		void addPassengerName(string passengerName);
	private:
		int planeId;
		string origin; 
		string destination; 
		string departureDate; 
		string departureTime;
		string returnDate; 
		string returnTime;
		vector<int> passengerIds;
		vector<string> passengerNames;
};

#endif