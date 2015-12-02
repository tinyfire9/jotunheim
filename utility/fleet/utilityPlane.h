/* 
 * File:   utilityPlane.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */
#include "../../fleet/plane/newPlane.h"
#include <string>
#include <iostream>
#include "../utility.h"
 

#ifndef UTILITYPLANE_H
#define UTILITYPLANE_H

class PlaneUtility : public utility{

    public:
    PlaneUtility(){};
    void writeFile(vector<StoragePlane> &storagePlanes,vector<NewPlane> &NewPlanes,string path);
    void populateReadArray(vector<StoragePlane> &planes,string path);
    void split(string line, vector<string> &words);
    int stringToInt(string word);
    
/*
    private:
    
    string getSeats;
    string getFleet; // maybe is string. not sure yet
    string getStatus;
    int getFirstClassRows;
    int getEconomyRows;
    int getEconomyPlusRows;
    int getPlaneId; 
    int getColumn;

    */
    //void addPlane(string planeId,string status,int column,int firstClassRows,int economyRows,int economyPlusRows); 
    //void updateData(string seats, int planeId, string fleet);   
    //string listAvailablePlanes(string status,string fleet);
    //vector<int> seatData;
    //vector<string> planeIdData;
  
    
};

#endif 
