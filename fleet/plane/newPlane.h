#include <iostream>
#include <string>
#include "plane.h"
#include <sstream>
#include <fstream>
using namespace std;

#ifndef NEW_PLANE_H
#define NEW_PLANE_H

class NewPlane : public Plane{
public:
	NewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows)
	: Plane(column, number_of_first_class_rows, number_of_economy_class_rows, number_of_economy_plus_rows){ //new function for new plane when added
		string line = ""; // set line to empty
		int max = 0;
		int id = 0;
		fstream readStream;
		readStream.open("./data/plane.txt"); // open the plane file and read 
		while(getline(readStream,line))
		{
			stringstream ss(line);
			ss >> id;
			if(id > max)
			{
				max = id;
			}
		}
		NewPlane::planeNumber = max + 1;

	}

	int getPlaneNumber(); // get plane number function

private:
	int planeNumber;
};
#endif
