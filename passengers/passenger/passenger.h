#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Passenger
{
	public:
		Passenger(
			int passengerId, 
			string firstName,
			string lastName,
			string seatNumber,
			int flightNumber
		);		
		int getPassengerId();
		int getFlightNumber();
		string getFirstName();
		string getLastName();
		string getSeatNumber();
		

		vector<int> getPassengerIds();
		vector<string> getPassengerNames();

		void setPassengerId(int passengerId);
		void setFlightNumber(int flightNumber);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setSeatNumber(string seatNumber);

		//void addPassengerId(int passengerId);
		void addFlightNumber(int flightNumber);
		//void addPassengerName(string passengerName);
		//void addPassengerSeat(string passengerSeat);
		

	private:
		int passengerId;
		string firstName;
		string lastName;
		string seatNumber;
		//vector<int> passengerIds;
		vector<int> flightNumbers;
		//vector<string> passengerNames;
		//vector<string> passengerSeat;
};