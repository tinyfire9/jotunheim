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
            int plane_id,
            int column,
            string number_of_economy_class_rows,
            string number_Of_economy_plus_rows,
            string number_of_first_class_rows
            
          );   
      
    int get_plane_id ();
   
    int get_column();

    string get_number_of_economy_class_rows();

    string get_number_of_economy_plus_rows();

    string get_number_of_first_class_rows();

    vector<int> getPassengerIds();

    vector<string> getPassengerSeats();  

    void set_column(int column);
    
    void set_number_of_economy_class_rows(string number_of_economy_class_rows);
    
    void set_number_of_economy_plus_rows(string number_of_economy_plus_rows);
    
    void set_number_of_first_class_rows(string number_of_first_class_rows);
    
    void addPassengerId(int passengerId);

    void addPassengerSeat(string passengerSeat);


private:
    int plane_id;
    int column;
    string number_of_economy_class_rows;
    string number_of_economy_plus_rows;
    string number_of_first_class_rows;
    vector<int> passengerIds;
    vector<string> passengerSeats;
    
   
};

#endif	/* PLANE_H */

