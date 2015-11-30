#include <iostream>
#include "fleet.h"
#include "./plane/newPlane.cpp"

Fleet::Fleet(){
	Fleet::utility.populateReadArray(Fleet::storagePlanes);
}

void Fleet::addPlane(
	int plane_id,
	int column,
	string number_of_economy_class_rows,
	string number_of_economy_plus_rows,
	string number_of_first_class_rows ){
	
	NewPlane plane(
		plane_id,
		column,
		number_of_economy_class_rows,
		number_of_economy_plus_rows,
		number_of_first_class_rows
	);
	Fleet::newPlanes.push_back(plane);
	Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes);
}