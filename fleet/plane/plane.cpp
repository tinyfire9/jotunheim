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

#endif
