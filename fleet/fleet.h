#include <iostream>
#include <vector>
#include "../utility/fleet/utilityPlane.cpp"

class Fleet
{
public:
	Fleet();
	void addPassenger(int planeNumber, int passengerId, string seat);
	void addPlane(int column, string number_of_first_class_rows, string number_of_economy_class_rows, string number_of_economy_plus_rows);
private:
	vector<StoragePlane> storagePlanes;
	vector<NewPlane> newPlanes;
	PlaneUtility utility;
};

