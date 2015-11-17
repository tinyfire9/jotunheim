#include<iostream>
#include<string>
using namespace std;

/*
	@TODO
		* document each method
*/

class Flight
{
	public:
		int getId();
		int getFlightNumber();
		string getOrigin(); 
		string getDestination(); 
		string getDepartureDate(); 
		string getDepartureTime();
		string getReturnDate(); 
		string getReturnTime();
		vector<int> getPassengerIds();
		vector<string> getPassengerNames();
		int setFlightNumber();
		string setOrigin(); 
		string setDestination(); 
		string setDepartureDate(); 
		string setDepartureTime();
		string setReturnDate(); 
		string setReturnTime();
		vector<int> setPassengerIds();
		vector<string> setPassengerNames();
	private:
		int id;
		int flightNumber;
		string origin; 
		string destination; 
		string departureDate; 
		string departureTime;
		string returnDate; 
		string returnTime;
		vector<int> passengerIds;
		vector<string> passengerNames;
}