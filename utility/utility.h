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
    int generatedID(int &array);
    void writeFile(int &array,string filename);
    void populateReadArray(int &array, string filename);
    vector<int> getData();
    
    
    
};

#endif	/* UTILITY_H */

