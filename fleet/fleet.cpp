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
	bool duplicatePassenger;
	bool duplicateSeat;

	for (int i = 0; i < Fleet::storagePlanes.size(); i++)
	{
		duplicatePassenger = find(
			Fleet::storagePlanes[i].getPassengerIds().begin(), 
			Fleet::storagePlanes[i].getPassengerIds().end(), planeNumber 
		) != Fleet::storagePlanes[i].getPassengerIds().end();

		duplicateSeat = find(
			Fleet::storagePlanes[i].getPassengerSeats().begin(), 
			Fleet::storagePlanes[i].getPassengerSeats().end(), seat 
		) != Fleet::storagePlanes[i].getPassengerSeats().end();

		cout << Fleet::storagePlanes[i].getPlaneNumber() <<  " ==== " << planeNumber  <<  " -- " << duplicatePassenger <<  " -- " << duplicateSeat << endl;
	
		if(Fleet::storagePlanes[i].getPlaneNumber() == planeNumber && duplicatePassenger && duplicateSeat )
		{
			Fleet::storagePlanes[i].addPassengerId(passengerId);
			Fleet::storagePlanes[i].addPassengerSeat(seat);
			found = true;
		}
	}

	for (int i = 0; i < newPlanes.size(); i++)
	{
		duplicatePassenger = find(
			Fleet::newPlanes[i].getPassengerIds().begin(), 
			Fleet::newPlanes[i].getPassengerIds().end(), planeNumber 
		) != Fleet::newPlanes[i].getPassengerIds().end();

		duplicateSeat = find(
			Fleet::newPlanes[i].getPassengerSeats().begin(), 
			Fleet::newPlanes[i].getPassengerSeats().end(), seat 
		) != Fleet::newPlanes[i].getPassengerSeats().end();
		
		cout << "hee";
		if(Fleet::newPlanes[i].getPlaneNumber() == planeNumber && duplicatePassenger && duplicateSeat )
		{
			Fleet::newPlanes[i].addPassengerId(passengerId);
			Fleet::newPlanes[i].addPassengerSeat(seat);
			found = true;
		}
	}

	if(!found)
	{
		cout << "Entered plane number, " << planeNumber << ", does not exist! Please try again!" << endl;
	}
	else if(duplicatePassenger)
	{
		cout << "Passenger ID " << passengerId << ", with seat number " << seat << " is already taken in the flight !" << endl;
	}
	else
	{
		Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes, "../utility/data/plane.txt");
	}
    
}