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
    string getLastName();

    vector<int> getFlightNumber();
    vector<string> getPassengerSeats();  
 
    void setFirstName(string firstName);
    void setLastName(string lastName);

    void addFlightNumber(int flightNumber);
    void addPassengerSeat(string passengerSeat);


private:

    string firstName;
    string lastName;
    vector<int> flightNumbers;
    vector<string> passengerSeats;
    
   
};

#endif	

