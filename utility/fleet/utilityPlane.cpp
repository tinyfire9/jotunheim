/* 
 * File:   main.cpp
 * Author: Silvester
 *
 * Created on November 19, 2015, 9:14 PM
 */
#include <fstream> 
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <string>
#include "../../fleet/plane/storagePlane.h"
#include "utilityPlane.h"
using namespace std;



void PlaneUtility::populateReadArray(vector<StoragePlane> &planes, string path)// function to populate the read array
{


    PlaneUtility util;
	string line = "";
	string chunk = "";


	vector< vector<string> >data;
	fstream readStream;
	readStream.open(path.c_str());
	

	while(getline(readStream,line)) // read the row line
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss,chunk, '|') ) // read the row line and separate by "|"
		{
			row.push_back(chunk);

		}
		data.push_back(row);
         
	}

	for(int i = 0; i < data.size(); i++ )
	{
		vector<string> chunks;
		vector< vector<string> > passenger;
		util.split(data[i][0], chunks); 

		StoragePlane Plane(
			util.stringToInt(chunks[0]), // separated data by chunks and converting them from string to int while storing them into the storage plane
			util.stringToInt(chunks[1]),
			util.stringToInt(chunks[2]),
			util.stringToInt(chunks[3]),
			util.stringToInt(chunks[4])
	    );

	    for(int j = 1; j< data[i].size(); j++)
	    {
          vector<string> passengerInfo;
          util.split(data[i][j],passengerInfo); // Split the data 
          Plane.addPassengerId(util.stringToInt(passengerInfo[0])); // add passenger id into the plane with converting the string id to int
          Plane.addPassengerSeat(passengerInfo[1]);// add passenger seat into the plane with passenger information

	    }
	    planes.push_back(Plane);
	}

}

void PlaneUtility::writeFile(vector<StoragePlane> &storagePlanes, vector<NewPlane> &NewPlanes,string path)// function to write the planeutility into the file along with the path
{
	string pipe = "|";
	ofstream outputStream;
	string outputData = "";
	outputStream.open(path.c_str());
	for (int i = 0; i< storagePlanes.size(); i++) // iterates the storagePlane size
		//output all the plane information and put it into the temporarily vector
	{
		outputStream << storagePlanes[i].getPlaneNumber() << " " << storagePlanes[i].get_column() << " ";
		outputStream << storagePlanes[i].get_number_of_first_class_rows() << " " << storagePlanes[i].get_number_of_economy_class_rows() << " ";
	    outputStream << storagePlanes[i].get_number_of_economy_plus_rows();
	    vector<int> passengerIds = storagePlanes[i].getPassengerIds();
	    vector<string> passengerNames = storagePlanes[i].getPassengerSeats();
	    for (int j = 0; j < passengerIds.size(); j++)
	    {
	    	outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerNames[j];
	    }
	    outputStream << endl;

     }
   for (int i =0 ; i < NewPlanes.size(); i++)
 {
	//cout << NewPlanes[i].get_plane_id() << endl;
	outputStream << NewPlanes[i].getPlaneNumber() << " " << NewPlanes[i].get_column() << " ";
    outputStream << NewPlanes[i].get_number_of_first_class_rows() << " " << NewPlanes[i].get_number_of_economy_class_rows() << " ";
    outputStream << NewPlanes[i].get_number_of_economy_plus_rows() << " ";
    vector<int> passengerIds = NewPlanes[i].getPassengerIds(); // gets the passenger ids and put into the new planes vector temporarily
    vector<string> passengerSeats = NewPlanes[i].getPassengerSeats(); // gets the passenger seats and put into the new passenger vector temporarily
    for (int j =0; j < passengerIds.size(); j++)
    {
    	outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerSeats[i]; 
    }
    outputStream << endl;
  }

  outputStream.close();
}



void PlaneUtility::split(string line, vector<string> &words) // function to split the data information
{
	stringstream ss(line);
	string word = "";
	while(ss >> word)
	{
		words.push_back(word); 
	}
}

int PlaneUtility::stringToInt(string word) // function to convert the string to int
{
	stringstream ss(word);
	int intVersion;
	ss >> intVersion;
	return intVersion;
}

