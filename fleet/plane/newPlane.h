#include <iostream>
#include <string>
#include "plane.cpp"
#include "../../utility/fleet/utilityPlane.cpp"

using namespace std;

#ifdef NEW_PLANE_H
#define NEW_PLANE_H

PlaneUtility util;

class NewPlane : public Plane{
public:
	NewPlane(int planeId, int columns, int FirstClassRows, int EconomyClassRows, int EconomyPlusRows)
	: Plane(planeId, columns, FirstClassRows, EconomyClassRows, EconomyPlusRows)
	{
		NewPlane::planeNumber = util.generateId();
	}

	int getPlaneNumber();

private:
	int planeNumber;
};

#endif