/* 
 * File:   main.cpp
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:27 PM
 */

#include <cstdlib>
#include "plane.h"

using namespace std;


Plane::Plane(   
    int plane_id,
    int column,
    int number_of_economy_class_rows,
    int number_of_economy_plus_rows,
    int number_of_first_class_rows   
){
 
    
    
}




int Plane::get_plane_id(int id)
{
    int given_plane_id = id;
    
    cout << "PLANE ID >> " << given_plane_id << " \n";
    
    return given_plane_id;
    
}

int Plane::get_column(int column)
{
     int given_column = column;
    
     cout << "get_column >> " << given_column << " \n";
    
     return given_column;
}

int Plane::get_number_of_economy_class_rows(int economy_class_rows)
{
      
    int given_economy_class_rows = economy_class_rows;
    
    cout << "ECONOMY CLASS ROWS >> " << given_economy_class_rows << " \n";
    
    return given_economy_class_rows;  
}

int Plane::get_number_of_economy_plus_rows(int economy_plus_rows)
{
    int given_economy_plus_rows = economy_plus_rows;
    
    cout << "ECONOMY PLUS ROWS >> " << given_economy_plus_rows << " \n";
    
    return given_economy_plus_rows;
}

int Plane::get_number_of_first_class_rows(int first_class_rows)
{
    
    int given_number_of_first_class_rows = first_class_rows;
    
    cout << "FIRST CLASS ROWS >> " << given_number_of_first_class_rows << " \n";
    
   return given_number_of_first_class_rows; 
}

void Plane::set_column(int column)
{

    
}

void Plane::set_number_of_economy_class_rows(const int rows)
{
    
}

void Plane::set_number_of_economy_plus_rows(const int rows)
{
    
}

void Plane::set_number_of_first_class_rows(const int rows)
{
    
}


int main() {

    Plane myplane;
    
    myplane.get_number_of_first_class_rows(890);
    myplane.get_number_of_economy_plus_rows(7723);
    myplane.get_number_of_economy_class_rows(123);
    myplane.get_plane_id(23);
    myplane.get_column(5);
    
    return 0;
}

