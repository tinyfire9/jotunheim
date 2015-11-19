/* 
 * File:   plane.h
 * Author: Silvester
 *
 * Created on November 17, 2015, 9:28 PM
 */

#include<iostream>
#include<string>
#include<fstream>
#ifndef PLANE_H
#define	PLANE_H
using namespace std;


class Plane
{
public:
    
    Plane(
            int plane_id,
            int column,
            int number_of_economy_class_rows,
            int number_Of_economy_plus_rows,
            int number_of_first_class_rows
            
          );   
      
    int get_plane_id ();
   
    int get_column();

    int get_number_of_economy_class_rows();

    int get_number_of_economy_plus_rows();

    int get_number_of_first_class_rows();

    
    
    
    void set_column(int column);
    
    void set_number_of_economy_class_rows(const int rows);
    
    void set_number_of_economy_plus_rows(const int rows);
    
    void set_number_of_first_class_rows(const int rows);
    
    
private:
    int plane_id;
    int column;
    int number_of_economy_class_rows;
    int number_of_economy_plus_rows;
    int number_of_first_class_rows;
    
    
   
};

#endif	/* PLANE_H */

