#include <iostream>
#include <string>
#include "plane.h"
using namespace std;

#ifndef STORAGE_PLANE_H
#define STORAGE_PLANE_H

class StoragePlane : public Plane{
public:
	StoragePlane(int plane_id, int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows)
	: Plane(column, number_of_first_class_rows, number_of_economy_class_rows, number_of_economy_plus_rows)
	{
		StoragePlane::plane_id=  plane_id;
	}
	int getPlaneNumber();
private:
	int plane_id;


};				

#endif