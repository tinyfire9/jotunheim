#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

Passenger::Passenger(string firstName, string lastName, string seatNumber, int flightNumber){
	Passenger::firstName = firstName;
	Passenger::lastName = lastName;
	Passenger::seatNumber = seatNumber;
	Passenger::flightNumbers.push_back(flightNumber);
}

int Passenger::getId(){
	return Passenger::passengerId;
}

string Passenger::getFirstName(){
	return Passenger::firstName;
}

string Passenger::getLastName(){
	return Passenger::lastName;
}

string Passenger::getSeatNumber(){
	return Passenger::seatNumber;
}

vector<int> Passenger::getFlightNumbers(){
	return Passenger::flightNumbers;
}

void Passenger::setFirstName(string firstName){
	Passenger::firstName = firstName;
}

void Passenger::setLastName(string lastName){
	Passenger::lastName = lastName;
}

void Passenger::setSeatNumber(string seatNumber){
	Passenger::seatNumber = seatNumber;
}

void Passenger::addFlightNumber(int flightNumber){
	Passenger::flightNumbers.push_back(flightNumber);
}
