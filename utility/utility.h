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

class utility 

{ 
private:
    
    
    int generatedId;
    string writeFromFilename;
    string readFromFilename;
    vector<int> data;
    
    
public:
	utility(){};
    virtual void writeFile(int &array,string filename){};
    // virtual void populateReadArray(vector<Flight> &flights, string filename){};
    //virtual void populateReadArray(vector<Plane> &planes, string filename){};
    virtual void populateReadArray(vector<Passenger> &planes, string filename){};
};

#endif	/* UTILITY_H */

