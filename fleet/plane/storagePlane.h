#include <iostream>
#include <string>
#include "plane.cpp"
using namespace std;

#ifndef STORAGE_PLANE_H
#define STORAGE_PLANE_H

class StoragePlane : public Plane{
public:
	StoragePlane(int planeId, int columns, int FirstClassRows, int EconomyClassRows,int EconomyPlusRows)
	: Plane(planeId, columns, FirstClassRows, EconomyPlusRows,EconomyClassRows)
	{
		StoragePlane::planeNumber = planeNumber;
	}
	int getPlaneNumber();
private:
	int planeNumber;
};				

#endif