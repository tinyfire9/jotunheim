/* 
 * File:   main.cpp
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:27 PM
 */

#include <cstdlib>
#include "plane.h"
#include <vector>
#include <string>

using namespace std;

#ifndef PLANE_CPP
#define PLANE_CPP


Plane::Plane(   
    int column, 
    int number_of_first_class_rows,          
    int number_of_economy_class_rows,
    int number_of_economy_plus_rows
    
){
 
 Plane::column = column;
 Plane::number_of_first_class_rows = number_of_first_class_rows;
 Plane::number_of_economy_class_rows = number_of_economy_class_rows;
 Plane::number_of_economy_plus_rows = number_of_economy_plus_rows;
    
}

int Plane::get_column() {
    return Plane::column;
    
}

int Plane::get_number_of_economy_class_rows() {
    return Plane::number_of_economy_class_rows;
    
}

int Plane::get_number_of_economy_plus_rows() {
    return Plane::number_of_economy_plus_rows;
}

int  Plane::get_number_of_first_class_rows() {
    return Plane::number_of_first_class_rows;    
}

vector<int> Plane::getPassengerIds(){
    return Plane:: passengerIds;
}

vector<string> Plane::getPassengerSeats()
{
    return Plane::passengerSeats;
}

void Plane::set_column(int column)
{
    Plane::column = column;    
}

void Plane::set_number_of_economy_class_rows(int economy_class_rows)
{
    Plane::number_of_economy_class_rows = economy_class_rows;
}

void Plane::set_number_of_economy_plus_rows(int economy_plus_class_rows)
{
    Plane::number_of_economy_plus_rows = economy_plus_class_rows;
    
}

void Plane::set_number_of_first_class_rows(int first_class_rows)
{
    Plane::number_of_first_class_rows = first_class_rows;
}

void Plane::addPassengerId(int passengerId)
{
    Plane::passengerIds.push_back(passengerId);
}

void Plane::addPassengerSeat(string passengerSeat)
{
    Plane::passengerSeats.push_back(passengerSeat);
}

bool Plane::deletePassenger(int passengerId, string passengerSeat){
    bool passengerIdFound = false;
    bool passengerSeatFound = false;
    bool deleted = false;
    int passengerIdIndex, passengerSeatIndex;

    // iterate through each seat number and check if the entered seat number exists
    for (int i = 0; i < Plane::passengerSeats.size(); i++)
    {
        if(Plane::passengerSeats[i] == passengerSeat)
        {
            passengerSeatFound = true;
            passengerSeatIndex = i;
        }
    }
    // iterate through each passengerId and check if the entered passengerId exists
    for (int i = 0; i < Plane::passengerIds.size(); i++)
    {
        if(Plane::passengerIds[i] == passengerId)
        {
            passengerIdFound = true;
            passengerIdIndex = i;
        }
    }
    //if, both, passengerId and seatNumber exists remove passenger 
    if((passengerIdFound == true) && (passengerSeatFound == true))
    {
        Plane::passengerSeats.erase(Plane::passengerSeats.begin() + passengerSeatIndex);
        Plane::passengerIds.erase(Plane::passengerIds.begin() + passengerIdIndex);
        deleted = true;
    }
    return deleted;
}

bool Plane::deleteLastPassenger(){
    bool deleted = false;
    if(Plane::passengerIds.size() == Plane::passengerSeats.size())
    {
       Plane::passengerSeats.erase(Plane::passengerSeats.begin() + (Plane::passengerSeats.size()-1));
       Plane::passengerIds.erase(Plane::passengerIds.begin() + (Plane::passengerIds.size()-1));
       deleted = true;
    }
    return deleted;
}

#endif
