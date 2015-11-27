/* 
 * File:   utilityPlane.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */

#include <string>
#include <iostream>
#include <vector>
 #include "../../fleet/plane/plane.cpp"
#include "../utility.h"
 


#ifndef UTILITYPLANE_H
#define	UTILITYPLANE_H

using namespace std;

class PlaneUtility{
    
private:
    
    string getSeats;
    string getFleet; // maybe is string. not sure yet
    string getStatus;
    int getFirstClassRows;
    int getEconomyRows;
    int getEconomyPlusRows;
    int getPlaneId; 
    int getColumn;
    
    
public:
    
  
    int generatedId(vector<Plane> &planes);
    void populateReadArray();
    void addPlane(string planeId,string status,int column,int firstClassRows,int economyRows,int economyPlusRows); 
    void updateData(string seats, int planeId, string fleet);   
    string listAvailablePlanes(string status,string fleet);
    vector<int> seatData;
    vector<string> planeIdData;

     
    
};

#endif	/* UTILITYPLANE_H */

