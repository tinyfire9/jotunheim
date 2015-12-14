/* 
 * File:   utility.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 8:47 PM
 */
#include <string>
#include <iostream>
#include <vector>

#ifndef UTILITY_H
#define	UTILITY_H

using namespace std;

/* An interface to be implemented by flightScheduleUtility, UtilityPassenger and UtilityPlane*/

class utility 
{ 
private:
    
    
    int generatedId;
    string writeFromFilename;
    string readFromFilename;
    vector<int> data;
    
    
public:
	utility(){};
	/*
		Pre-condition : expects a storageFlight type vector,  a newFlight type vector and a file path
		Post-condition : loops through each item and gets all the data by from each method from both vectors 
				and writes it to a file specified by the user
	*/
    virtual void writeFile(vector<StorageFlight> &storageFlights,vector<NewFlight> &newFlights, string path){};
    /*
		Pre-condition : expects a line and a vector 
		Post-condition : splits the line by space and pushes each chunk into the vector
    */
    virtual void populateReadArray(vector<StorageFlight> &flights, string path){};
    /*
		Pre-condition : expects a line and a vector 
		Post-condition : splits the line by space and pushes each chunk into the vector
    */
    virtual void split(string line, vector<string> &words){};
    /*
		Pre-condition : expects an integer of type string
		Post-condition : return the integer version of the string
    */
    virtual int stringToInt(string words){};
};

#endif	/* UTILITY_H */

