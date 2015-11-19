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
    
)
{
 
 Plane::plane_id = plane_id;
 Plane::column = column;
 Plane::number_of_first_class_rows = number_of_first_class_rows;
 Plane::number_of_economy_class_rows = number_of_economy_class_rows;
 Plane::number_of_economy_plus_rows = number_of_economy_plus_rows;
    
}
int Plane::get_plane_id(){
    return Plane::plane_id;
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

int Plane::get_number_of_first_class_rows() {
    return Plane::number_of_first_class_rows;    
}

void Plane::set_column(int column)
{
    Plane::column = column;    
}

void Plane::set_number_of_economy_class_rows(const int economy_class_rows)
{
    Plane::number_of_economy_class_rows = economy_class_rows;
}

void Plane::set_number_of_economy_plus_rows(const int economy_plus_class_rows)
{
    Plane::number_of_economy_plus_rows = economy_plus_class_rows;
    
}

void Plane::set_number_of_first_class_rows(const int first_class_rows)
{
    Plane::number_of_first_class_rows = first_class_rows;
}


int main() 

{
    
       
    return 0;
}

