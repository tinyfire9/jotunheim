#include <iostream>
#include <string>
#include "plane.cpp"
using namespace std;

#ifndef STORAGE_PLANE_H
#define STORAGE_PLANE_H

class StoragePlane : public Plane{
public:
	StoragePlane(int plane_id, int column, string number_of_economy_class_rows, string number_of_economy_plus_rows,string number_of_first_class_rows)
	: Plane(plane_id, column, number_of_economy_class_rows, number_of_economy_plus_rows,number_of_first_class_rows)
	{
	}
};				

#endif