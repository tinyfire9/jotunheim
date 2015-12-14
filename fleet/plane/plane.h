/* 
 * File:   plane.h
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:28 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#ifndef PLANE_H
#define	PLANE_H
using namespace std;


class Plane
{
public:
    
    Plane(
            int column,
            int number_of_first_class_rows,
            int number_of_economy_class_rows,
            int number_Of_economy_plus_rows
            
            
          );   
      
   
    int get_column();
     //Post-condition : returns, an integer, #column number
    int get_number_of_economy_class_rows();
     //Post-condition : returns, an integer, #economy class rows 
    int get_number_of_economy_plus_rows();
    //Post-condition : returns, an integer, #economy plus class rows
    int get_number_of_first_class_rows();
    //Post-condition : returns, an integer, #first class rows
    vector<int> getPassengerIds();
    //Post-condition : returns, a vector of integer, a list passengerIds are in the plane
    vector<string> getPassengerSeats();  
    //Post-condition : returns, a vector of strings, a list of the passeger seats 
    void set_column(int column);
    //Pre-condition : expects, a integer , the new origin of the flight 
    //Post-condition : sets the origin to the new origin 
    void set_number_of_economy_class_rows(int number_of_economy_class_rows);
    //Pre-condition : expects, a integer , the new economy class rows of the plane 
    //Post-condition : sets the economy plus class to the new economy class rows 
    void set_number_of_economy_plus_rows(int number_of_economy_plus_rows);
    //Pre-condition : expects, a integer , the new economy plus class rows of the plane 
    //Post-condition : sets the economy class rows to the new economy plus class rows 
    void set_number_of_first_class_rows(int number_of_first_class_rows);
    //Pre-condition : expects, a integer , the new first class rows of the plane
    //Post-condition : sets the first class rows to the new first class rows 
    void addPassengerId(int passengerId);
    //Pre-condition : expects, a integer , the passengerID ("4")
    //Post-condition : adds the passengerID to the current passengers list of the plane
    void addPassengerSeat(string passengerSeat);
    //Pre-condition : expects, a string , the passengerSeat("4A")
    //Post-condition : adds the passengerSeat to the current passengers list of the plane
    bool deletePassenger(int passengerId, string passengerSeat);

    bool deleteLastPassenger();

private:

    int column;
    int number_of_economy_class_rows;
    int number_of_economy_plus_rows;
    int number_of_first_class_rows;
    vector<int> passengerIds;
    vector<string> passengerSeats;
    
};

#endif	/* PLANE_H */

