/* 
 * File:   passenger.cpp
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:27 PM
 */

#include <cstdlib>
#include "passenger.h"
#include <vector>
#include <string>

using namespace std;

#ifndef PASSENGER_CPP
#define PASSENGER_CPP


Passenger::Passenger(   
    string firstName,
    string lastName
   
){
 
Passenger::firstName = firstName;
Passenger::lastName = lastName;
    
}


string Passenger::getFirstName(){
    return Passenger::firstName;
}

string Passenger::getLastName(){
    return Passenger::lastName;
}

vector<int> Passenger::getFlightNumber(){
    return Passenger:: flightNumbers;
}

vector<string> Passenger::getPassengerSeats()
{
    return Passenger::passengerSeats;
}

void Passenger::setFirstName(string firstName)
{
    Passenger::firstName = firstName;
}

void Passenger::setLastName(string lastName)
{
    Passenger::lastName = lastName;
}


void Passenger::addFlightNumber(int flightNumber)
{
    Passenger::flightNumbers.push_back(flightNumber);
}

void Passenger::addPassengerSeat(string passengerSeat)
{
    Passenger::passengerSeats.push_back(passengerSeat);
}

#endif
