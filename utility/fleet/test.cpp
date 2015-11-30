#include <iostream>
#include "../../fleet/plane/newPlane.cpp"
#include "utilityPlane.cpp"

int main() {


std::vector<StoragePlane> storagePlanes;
std::vector<NewPlane> newPlanes;
PlaneUtility test;

test.populateReadArray(storagePlanes);

NewPlane test2(1,6,"First","econom","plus");
test2.addPassengerId(1234);
test2.addPassengerSeat("5a");

test2.addPassengerId(4566);
test2.addPassengerSeat("8a");

test2.addPassengerId(8765);
test2.addPassengerSeat("9a");

newPlanes.push_back(test2);
test.writeFile(storagePlanes,newPlanes);

NewPlane test3(2,7,"3","6","8");
test3.addPassengerId(8999);
test3.addPassengerSeat("2b");

test3.addPassengerId(9999);
test3.addPassengerSeat("5C");

newPlanes.push_back(test3);
test.writeFile(storagePlanes, newPlanes);





return 0;
	
}