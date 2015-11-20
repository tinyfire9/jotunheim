/* 
 * File:   utilityPlane.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */

#include <string>
#include <iostream>
#include <vector>


#ifndef UTILITYPLANE_H
#define	UTILITYPLANE_H

using namespace std;

class planeUtility{
    
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
    
    //Missing plane_id
    void addPlane(string planeId,string status,int column,int firstClassRows,int economyRows,int economyPlusRows); 
    void updateData(string seats, int planeId, string fleet);   
    string listAvailablePlanes(string status,string fleet);
    vector<int> seatData;
    vector<string> planeIdData;
    //vector<string> fleet; not sure yet 
     
    
};

#endif	/* UTILITYPLANE_H */

