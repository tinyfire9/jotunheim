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
		Pre-condition : expects a file path //to be Overloaded
		Post-condition : write to 
	*/
    virtual void writeFile(string path){};
    /*
        Pre-condition : expects a file path //to be Overloaded
        Post-condition : reads to file
    */
    virtual void populateReadArray(string path){};
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

