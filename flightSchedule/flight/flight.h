#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight
{
	public:
		//Initalization
		Flight(
			int planeId,
			string origin, 
			string destination,
			string departureDate,
			string departureTime,
			string returnDate,
			string returnTime
		);
		//Post-condition : returns, an integer, planeId
		int getPlaneId();
		//Post-condition : returns, an integer, flight number
		int getFlightNumber();
		//Post-condition : returns, a string, the origin of the flight
		string getOrigin(); 
		//Post-condition : returns, a string, the destination of the flight
		string getDestination(); 
		//Post-condition : returns, a string, the departure date(MM/DD/YYYY) of the flight
		string getDepartureDate(); 
		//Post-condition : returns, a string, the departure time(HH:MM) of the flight
		string getDepartureTime();
		//Post-condition : returns, a string, the return date(MM/DD/YYYY) of the flight
		string getReturnDate(); 
		//Post-condition : returns, a string, the return time(HH:MM) of the flight
		string getReturnTime();
		//Post-condition : returns, a vector of integers, a list of passengers ids who are in this flights
		vector<int> getPassengerIds();
		//Post-condition : returns, a vector of strings, a list of names('LastName, FirstName') who are in this flights
		vector<string> getPassengerNames();
		//Pre-condition : expects, an interger, the new planeId 
		//Post-condition : sets the planeId to the new planeId
		void setPlaneId(int planeId);
		//Pre-condition : expects, a string , the new origin of the flight 
		//Post-condition : sets the origin to the new origin 
		void setOrigin(string origin); 
		//Pre-condition : expects, a string , the new destination of the flight 
		//Post-condition : sets the destination to the new destination 
		void setDestination(string destination); 
		//Pre-condition : expects, a string , the new departure date(MM/DD/YY) of the flight 
		//Post-condition : sets the departure date to the new departure date 
		void setDepartureDate(string departureDate);
		//Pre-condition : expects, a string , the new departure time(HH:MM) of the flight 
		//Post-condition : sets the departure time to the new departure time 		 
		void setDepartureTime(string departureTime);
		//Pre-condition : expects, a string , the new return date(MM/DD/YY) of the flight 
		//Post-condition : sets the return date to the new return date 
		void setReturnDate(string returnDate);
		//Pre-condition : expects, a string , the new return time(HH:MM) of the flight 
		//Post-condition : sets the return time to the new return time  
		void setReturnTime(string returnTime);
		//Pre-condition : expects, an integer , the passengerId
		//Post-condition : adds the passengerId to the current passengers list of the flight 	
		void addPassengerId(int passengerId);
		//Pre-condition : expects, a string , the passenger name ('LastName, FirstName')
		//Post-condition : adds the passenger name to the current passengers list of the flight
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