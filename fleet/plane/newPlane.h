#include <iostream>
#include <string>
#include "plane.cpp"
#include <sstream>
#include <fstream>
using namespace std;

#ifndef NEW_PLANE_H
#define NEW_PLANE_H

class NewPlane : public Plane{
public:
	NewPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows)
	: Plane(column, number_of_first_class_rows, number_of_economy_class_rows, number_of_economy_plus_rows){
		string line = "";
		int max = 0;
		int id = 0;
		fstream readStream;
		readStream.open("../data/plane.txt");
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

	int getPlaneNumber();

private:
	int planeNumber;
};
#endif
