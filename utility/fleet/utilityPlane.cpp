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
#include "../../fleet/plane/storagePlane.cpp"
#include "utilityPlane.h"
using namespace std;



void PlaneUtility::populateReadArray(vector<StoragePlane> &planes){


    PlaneUtility util;
	string line = "";
	string chunk ="";
	vector< vector<string> >data;
	fstream readStream;
	readStream.open("../data/plane.txt");
	

	while(getline(readStream,line))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss,chunk, '|'))
		{
			row.push_back(chunk);

		}
		data.push_back(row);
         
	}


	for(int i = 0; i < data.size(); i++ )
	{
		vector<string> chunks;
		vector< vector<string> > passenger;
		util.split(data[i][0],chunks);

		StoragePlane Plane(
			util.stringToInt(chunks[0]),
			util.stringToInt(chunks[1]),
			chunks[2],
			chunks[3],
			chunks[4]
	    );

	    for(int j = 1; j< data[i].size(); j++)
	    {
          vector<string> passengerInfo;
          util.split(data[i][j],passengerInfo);
          Plane.addPassengerId(util.stringToInt(passengerInfo[0]));
          Plane.addPassengerName(passengerInfo[1] + " " + passengerInfo[2]);

	    }
	    planes.push_back(Plane);
	}

}

void writeFile(vector<StoragePlane> &storagePlanes, vector<NewPlane> &NewPlanes, string filename)
{
	string pipe = "|";
	ofstream outputStream;
	string outputData = "";
	outputStream.open("../data/plane.txt");
	for (int i = 0; i< storagePlanes.size(); i++)
	{
		outputStream << storagePlanes[i].get_plane_id() << " " << storagePlanes[i].get_column() << " ";
		outputStream << storagePlanes[i].get_number_of_first_class_rows() << " " << storagePlanes[i].get_number_of_economy_class_rows() << " ";
	    outputStream << storagePlanes[i].get_number_of_economy_plus_rows();
	    vector<int> passengerIds = storagePlanes[i].getPassengerIds();
	    vector<string> passengerNames = storagePlanes[i].getPassengerNames();
	    for (int j = 0; j < passengerIds.size(); j++)
	    {
	    	outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerNames[j];
	    }
	    outputStream << endl;

     }
   for (int i =0 ; i < NewPlanes.size(); i++)
 {
	cout << NewPlanes[i].get_plane_id() << endl;
	outputStream << NewPlanes[i].get_plane_id() << " " << NewPlanes[i].get_column() << " ";
    outputStream << NewPlanes[i].get_number_of_first_class_rows() << " " << NewPlanes[i].get_number_of_economy_class_rows() << " ";
    outputStream << NewPlanes[i].get_number_of_economy_plus_rows() << " ";
    vector<int> passengerIds = NewPlanes[i].getPassengerIds();
    vector<string> passengerNames = NewPlanes[i].getPassengerNames();
    for (int j =0; j < passengerIds.size(); j++)
    {
    	outputStream << " " << pipe << " " << passengerIds[j] << " " << passengerNames[i]; 
    }
    outputStream << endl;
  }

  outputStream.close();
}



void PlaneUtility::split(string line, vector<string> &words)
{
	stringstream ss(line);
	string word = "";
	while(ss >> word)
	{
		words.push_back(word);
	}
}

int PlaneUtility::stringToInt(string word)
{
	stringstream ss(word);
	int intVersion;
	ss >> intVersion;
	return intVersion;
}

