/* 
 * File:   utilityPassenger.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */
#include "../../passengers/passenger/newPassenger.h"
#include <string>
#include <iostream>
#include "../utility.h"
 

#ifndef UTILITYPASSENGER_H
#define UTILITYPASSENGER_H

class PassengerUtility : public utility{

    public:
    PassengerUtility(){};
    void writeFile(vector<StoragePassenger> &storagePassengers,vector<NewPassenger> &NewPassengers, string path);
    void populateReadArray(vector<StoragePassenger> &passengers ,string path);
    void split(string line, vector<string> &words);
    int stringToInt(string word);
    
};

#endif 
