#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

Passenger::Passenger(
	int passengerId,
	string firstName, 
	string lastName
	
)
{
	Passenger::passengerId = passengerId;
	Passenger::firstName = firstName;
	Passenger::lastName = lastName;
}

int Passenger::getPassengerId(){
	return Passenger::passengerId;
}

string Passenger::getFirstName(){
	return Passenger::firstName;
}

string Passenger::getLastName(){
	return Passenger::lastName;
}

vector<string> Passenger::getPassengerSeats(){
	return Passenger::passengerSeats;
}

vector<int> Passenger::getFlightNumber(){
	return Passenger::flightNumbers;
}
void Passenger::setPassengerId(int passengerId){
	Passenger::passengerId =  passengerId;
}

void Passenger::setFirstName(string firstName){
	Passenger::firstName = firstName;
}

void Passenger::setLastName(string lastName){
	Passenger::lastName = lastName;
}

void Passenger::addFlightNumber(int flightNumber){
	Passenger::flightNumbers.push_back(flightNumber);
}

void Passenger::addPassengerSeat(string passengerSeat){
	Passenger::passengerSeats.push_back(passengerSeat);
}
