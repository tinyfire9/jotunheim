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
    virtual void writeFile(string path){};
    virtual void populateReadArray(string path){};
    virtual void split(string line, vector<string> &words){};
    virtual int stringToInt(string word){};
};

#endif	/* UTILITY_H */

