#include <iostream>
#include "fleet.h"
#include "./plane/newPlane.cpp"
#include <algorithm>

Fleet::Fleet(){
	Fleet::utility.populateReadArray(Fleet::storagePlanes, "../utility/data/plane.txt");
}

void Fleet::addPlane(
	int column,
	string number_of_economy_class_rows,
	string number_of_economy_plus_rows,
	string number_of_first_class_rows ){
	
	NewPlane plane(
		column,
		number_of_economy_class_rows,
		number_of_economy_plus_rows,
		number_of_first_class_rows
	);
	Fleet::newPlanes.push_back(plane);
	Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes,"../utility/data/plane.txt");
}
void Fleet::addPassenger(int planeNumber, int passengerId, string seat){
	bool found = false;
	bool duplicatePassenger = false;
	bool duplicateSeat = false;
	for (int i = 0; i < Fleet::storagePlanes.size(); i++)
	{
		if(Fleet::storagePlanes[i].getPlaneNumber() == planeNumber)
		{
			found = true;
			vector<int> ids = Fleet::storagePlanes[i].getPassengerIds();
			vector<string> seatNumbers = Fleet::storagePlanes[i].getPassengerSeats();
			for (int j = 0; j < ids.size(); j++)
			{
				if(ids[j] == passengerId)
				{
					duplicatePassenger = true;
				}
			}
			for (int j = 0; j < seatNumbers.size(); j++)
			{
				if(seatNumbers[j] == seat)
				{
					duplicateSeat = true;
				}
			}
		}
		if((duplicatePassenger == false) && (duplicateSeat == false) && (found == true))
		{
			Fleet::storagePlanes[i].addPassengerId(passengerId);
			Fleet::storagePlanes[i].addPassengerSeat(seat);
		}
	}

	
	if(found == false)
	{
		cout << "Entered plane number, " << planeNumber << ", does not exist! Please try again!" << endl;
	}
	if(duplicatePassenger == true)
	{
		cout << "Passenger ID " << passengerId << ", with seat number " << seat << " is already taken in the flight !" << endl;
	}
	if(duplicateSeat == true)
	{
		cout << "Seat number " << seat << ", with passenger Id " << passengerId << " is already taken in the flight !" << endl;
	}
	else
	{
		Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes, "../utility/data/plane.txt");
	}
    
}