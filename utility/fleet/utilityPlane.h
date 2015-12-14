/* 
 * File:   utilityPlane.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */
#include "../../fleet/plane/newPlane.h"
#include "../../fleet/plane/storagePlane.h"
#include <string>
#include <iostream>
#include "../utility.h"
 

#ifndef UTILITYPLANE_H
#define UTILITYPLANE_H

class PlaneUtility : public utility{

    public:
    //Instansiate class
    PlaneUtility(){};
    /*
            Pre-condition : expects a storagePlane type vector,  a newPlane type vector and a file path
            Post-condition : loops through each item and gets all the data by from each method from both vectors 
                    and writes it to a file specified by the user
    */
    void writeFile(vector<StoragePlane> &storagePlanes,vector<NewPlane> &NewPlanes,string path);
    /*
            Pre-condition : expects a storagePlane type vector,  and a file path
            Post-condition : loops through each line of the text fil, creating a storagePlane object with the data
                    push each object the the vector 
    */
    void populateReadArray(vector<StoragePlane> &planes,string path);
            /*
            Pre-condition : expects a line and a vector 
            Post-condition : splits the line by space and pushes each chunk into the vector
     */
    void split(string line, vector<string> &words);
     /*
            Pre-condition : expects an integer of type string
            Post-condition : return the integer version of the string
    */
    int stringToInt(string word);
    
  
    
};

#endif 
