#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
using namespace std;

Flight::Flight(
		int id, 
		int flightNumber, 
		string origin, 
		string destination,
		string departureDate,
		string departureTime,
		string returnDate,
		string returnTime

	){
	Flight::id = id;
	Flight::flightNumber = flightNumber;
	Flight::origin = origin;
	Flight:: destination = destination;
	Flight::departureDate = departureDate;
	Flight::departureTime = departureTime;
	Flight::returnDate = returnDate;
	Flight::returnTime = returnTime; 
}

int Flight::getId(){
	return Flight::id;
}

int Flight::getFlightNumber(){
	return Flight::flightNumber;
}

string Flight::getOrigin(){
	return Flight::origin;
}

string Flight::getDestination(){
	return Flight::destination;
}

string Flight::getDepartureDate(){
	return Flight::departureDate;
}

string Flight::getDepartureTime(){
	return Flight::departureTime;
}

string Flight::getReturnDate(){
	return Flight::returnDate;
} 

string Flight::getReturnTime(){
	return Flight::returnTime;
}

vector<int> Flight::getPassengerIds(){
	return Flight::passengerIds;
}

vector<string> Flight::getPassengerNames()
{
	return Flight::passengerNames;
}

void Flight::setFlightNumber(int flightNumber)
{
	Flight::flightNumber = flightNumber;
}

void Flight::setOrigin(string origin)
{
	Flight::origin = origin;
} 

void Flight::setDestination(string destination)
{
	Flight::destination = destination;
} 

void Flight::setDepartureDate(string departureDate)
{
	Flight::departureDate = departureDate;
} 

void Flight::setDepartureTime(string departureTime)
{
	Flight::departureTime = departureTime;
}

void Flight::setReturnDate(string returnDate)
{
	Flight::returnDate = returnDate;
}

void Flight::setReturnTime(string returnTime)
{
	Flight::returnTime = returnTime;
}

void Flight::addPassengerId(int passengerId){
	Flight::passengerIds.push_back(passengerId);
}

void Flight::addPassengerName(string passengerName){
	Flight::passengerNames.push_back(passengerName);
}
