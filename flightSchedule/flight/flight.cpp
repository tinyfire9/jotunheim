#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
using namespace std;

#ifndef FLIGHT_CPP
#define FLIGHT_CPP

Flight::Flight(
		int planeId, 
		string origin, 
		string destination,
		string departureDate,
		string departureTime,
		string returnDate,
		string returnTime

	){
	Flight::planeId = planeId;
	Flight::origin = origin;
	Flight:: destination = destination;
	Flight::departureDate = departureDate;
	Flight::departureTime = departureTime;
	Flight::returnDate = returnDate;
	Flight::returnTime = returnTime; 
}

int Flight::getPlaneId(){
	return Flight::planeId;
}

string Flight::getOrigin(){
	return Flight::origin;
}

string Flight::getDestination(){ // get method for destionation
	return Flight::destination;
}

string Flight::getDepartureDate(){// get method for departure date
	return Flight::departureDate;
}

string Flight::getDepartureTime(){// get method for departure time
	return Flight::departureTime;
}

string Flight::getReturnDate(){// get method for return date 
	return Flight::returnDate;
} 

string Flight::getReturnTime(){// get method for return time
	return Flight::returnTime;
}

vector<int> Flight::getPassengerIds(){// get method for passenger ids 
	return Flight::passengerIds;
}

vector<string> Flight::getPassengerNames()// get method for passenger names
{
	return Flight::passengerNames;
}

void Flight::setPlaneId(int planeId) // set method for new plane id
{
	Flight::planeId = planeId;
}
// set method for new origin 
void Flight::setOrigin(string origin)// set method for new origin 
{
	Flight::origin = origin;
} 

void Flight::setDestination(string destination)// set method for new destination
{
	Flight::destination = destination;
} 

void Flight::setDepartureDate(string departureDate)// set method for new departure date 
{
	Flight::departureDate = departureDate;
} 

void Flight::setDepartureTime(string departureTime)// set method for new departure time
{
	Flight::departureTime = departureTime;
}

void Flight::setReturnDate(string returnDate)// set method for new return date 
{
	Flight::returnDate = returnDate;
}

void Flight::setReturnTime(string returnTime)// set method for new return time
{
	Flight::returnTime = returnTime;
}

void Flight::addPassengerId(int passengerId){ // adds the new passenger id into the passenger id vector
	Flight::passengerIds.push_back(passengerId);
}

void Flight::addPassengerName(string passengerName){ // adds the new passenger name into the passenger name vector 
	Flight::passengerNames.push_back(passengerName);
}

#endif