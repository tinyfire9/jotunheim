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
    return Passenger::firstName; // client first name
}

string Passenger::getLastName(){
    return Passenger::lastName; // client last name
}

vector<int> Passenger::getFlightNumber(){
    return Passenger:: flightNumbers; // gets the flight number that are stored in the vector
}

vector<string> Passenger::getPassengerSeats()
{
    return Passenger::passengerSeats; //  gets the passenger seats that are stored in the vector
}

void Passenger::setFirstName(string firstName)
{
    Passenger::firstName = firstName; // set client first name when adding new passenger
}

void Passenger::setLastName(string lastName)
{
    Passenger::lastName = lastName; // set client last name when adding new passenger
}


void Passenger::addFlightNumber(int flightNumber)
{
    Passenger::flightNumbers.push_back(flightNumber); // push the flight number into the vector so that the data will be stored
}

void Passenger::addPassengerSeat(string passengerSeat)
{
    Passenger::passengerSeats.push_back(passengerSeat); // push the passengerseat into the vector so that the data will be stored
}

#endif
