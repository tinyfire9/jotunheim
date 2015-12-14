/* 
 * File:   utilityPassenger.h
 * Author: Silvester
 *
 * Created on November 19, 2015, 10:01 PM
 */
#include "../../passengers/passenger/newPassenger.h"
#include "../../passengers/passenger/storagePassenger.h" 
#include <string>
#include <iostream>
#include "../utility.h"
 

#ifndef UTILITYPASSENGER_H
#define UTILITYPASSENGER_H

class PassengerUtility : public utility{

    public:
    //Instansiate class
    PassengerUtility(){};
    /*
			Pre-condition : expects a storagePassenger type vector,  a newPassenge type vector and a file path
			Post-condition : loops through each item and gets all the data by from each method from both vectors 
					and writes it to a file specified by the user
	*/
    void writeFile(vector<StoragePassenger> &storagePassengers,vector<NewPassenger> &NewPassengers, string path);
    /*
			Pre-condition : expects a storagePassenger type vector,  and a file path
			Post-condition : loops through each line of the text fil, creating a storagePassenger object with the data
					push each object the the vector 
	*/
    void populateReadArray(vector<StoragePassenger> &passengers ,string path);
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
