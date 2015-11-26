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

void Flight::setPlaneId(int planeId)
{
	Flight::planeId = planeId;
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

#endif