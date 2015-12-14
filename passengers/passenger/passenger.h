/* 
 * File:   passenger.h
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:28 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#ifndef PASSENGER_H
#define	PASSENGER_H
using namespace std;


class Passenger
{
public:
    
    Passenger(
            string firstName,
            string lastName     
          );   
      
    string getFirstName();
    //Post-condition : returns, a string, the first name of the passenger
    string getLastName();
    //Post-condition : returns, a string, the last name of the passenger

    vector<int> getFlightNumber();
    vector<string> getPassengerSeats();  
 
    void setFirstName(string firstName);
    //Pre-condition : expects, a string , the new first name of the passenger
    //Post-condition : sets the first name to the new passenger 
    void setLastName(string lastName);
    //Pre-condition : expects, a string , the new last name  of the passenger 
    //Post-condition : sets the last name to the new passenger 

    void addFlightNumber(int flightNumber);
    //Pre-condition : expects, a integer , the flightNumber ('flightNumber')
    //Post-condition : adds the flightNumber to the current flight list of the passenger
    void addPassengerSeat(string passengerSeat);
    //Pre-condition : expects, a string , the passengerSeat (passengerSeat)
    //Post-condition : adds the passengerSeat to the current passengers list of the passenger


private:

    string firstName;
    string lastName;
    vector<int> flightNumbers;
    vector<string> passengerSeats;
    
   
};

#endif	

