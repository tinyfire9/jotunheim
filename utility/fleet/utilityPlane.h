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
    
    string seats;
    string fleet; // maybe is string. not sure yet
    string status;
    int firstClassRows;
    int economyRows;
    int economyPlusRows;
    int planeId; 
    int column;
    
    
public:
    
    addPlane(
            string status,
            int column,
            int firstClassRows,
            int economyRows,
            int economyPlusRows
            );
    void updateData(&seats, &planeId, &fleet);
    
    string listAvailablePlanes(string status,string fleet);
    
    vector<int> seats;
    vector<string> planeId;
    //vector<string> fleet; not sure yet 
     
    
};

#endif	/* UTILITYPLANE_H */

