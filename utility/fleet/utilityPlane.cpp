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
#include "utilityPlane.h"
using namespace std;



int PlaneUtility::generatedId(vector<Plane> &planes){
	int maximum = 0;
	for(int i = 0; i < planes.size(); i++)
	{
		if(planes[i].get_plane_id() > maximum)
		{
			maximum = planes[i].get_plane_id();
		}
	}
	return maximum;
}

void PlaneUtility::populateReadArray(){


	string line = "";
	string chunk ="";
	vector< vector<string> >data;
	fstream readStream;

	readStream.open("../data/plane.txt");
	

	while(getline(readStream,line, '\n'))
	{
		vector<string> row;
		stringstream ss(line);
		while(getline(ss,chunk, '|'))
		{
			row.push_back(chunk);

		}
		data.push_back(row);
         
	}


	for(int i =0; i <data.size(); i++)
	{
		for(int p =0; p <data[i].size(); p++)
		{
			cout << data[i][p] << " | ";
		}

		cout << endl;
	}

}


