#include <string>
#include <vector>
using namespace std;

/*
	@TODO
		* document each method
*/
class Passenger
{
	public:
		Passenger(string firstName, string lastName, string seatNumber, int flightNumber);
		int getId();
		string getFirstName();
		string getLastName();
		string getSeatNumber();
		vector<int> getFlightNumbers();
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setSeatNumber(string seatNumber);
		void addFlightNumber(int flightNumber);
	private:
		int passengerId;
		string firstName;
		string lastName;
		string seatNumber;
		vector<int> flightNumbers;
};