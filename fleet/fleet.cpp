#include <iostream>
#include "fleet.h"
#include "./plane/newPlane.cpp"
#include <algorithm>

Fleet::Fleet(){
	Fleet::utility.populateReadArray(Fleet::storagePlanes, "./utility/data/plane.txt");
}

int Fleet::getAvailableFirstClassSeats(int planeId){
    int row, number_of_first_class_rows, planeIndex, totalAvailableSeats, column;
    for (int i = 0; i < Fleet::storagePlanes.size(); i++)
    {
    	if(Fleet::storagePlanes[i].getPlaneNumber() == planeId)
    	{
    		planeIndex = i;
    		number_of_first_class_rows = Fleet::storagePlanes[i].get_number_of_first_class_rows();
    		column = Fleet::storagePlanes[i].get_column();
    		totalAvailableSeats = column * number_of_first_class_rows;
		    std::vector<string> seats= Fleet::storagePlanes[planeIndex].getPassengerSeats();
		    for (int i = 0; i < seats.size(); i++)
		    {
		    	// computes for 2A - type of seat
		        if(seats[i].length() == 1)
		        {
		            row = Fleet::utility.stringToInt(seats[i].substr(0,1));

		        }
		        //computes for 23A - type
		        else if(seats[i].length() == 2)
		        {
		            row = Fleet::utility.stringToInt(seats[i].substr(0,2));
		        }
		        // subtract the number of seats taken from the total possible seats
	            if((row > 0) && (row <= number_of_first_class_rows))
	            {
	                totalAvailableSeats--;
	            }
		    }
    	}
    }
    return totalAvailableSeats;
}

int Fleet::getAvailableEconomyClassSeats(int planeId){
   int row, number_of_economy_class_rows, number_of_first_class_rows, planeIndex, totalAvailableSeats, column;
    for (int i = 0; i < Fleet::storagePlanes.size(); i++)
    {
    	if(Fleet::storagePlanes[i].getPlaneNumber() == planeId)
    	{
    		planeIndex = i;
    		number_of_first_class_rows = Fleet::storagePlanes[i].get_number_of_first_class_rows();
    		number_of_economy_class_rows = Fleet::storagePlanes[i].get_number_of_economy_class_rows();
    		column = Fleet::storagePlanes[i].get_column();
    		totalAvailableSeats = column * number_of_economy_class_rows;
		    std::vector<string> seats= Fleet::storagePlanes[planeIndex].getPassengerSeats();
		    for (int i = 0; i < seats.size(); i++)
		    {
		    	// computes for 2A - type of seat
		        if(seats[i].length() == 2)
		        {	
		            row = Fleet::utility.stringToInt(seats[i].substr(0,1));
		        }
		        //computes for 23A - type
		        else if(seats[i].length() == 3)
		        {
		        	row = Fleet::utility.stringToInt(seats[i].substr(0,2));
		        }
		        // subtract the number of seats taken from the total possible seats
	            if((row > number_of_first_class_rows) && (row <= number_of_first_class_rows + number_of_economy_class_rows))
	            {
	                totalAvailableSeats--;
	            }
		    }
    	}
    }
    return totalAvailableSeats;
}

int Fleet::getAvailableEconomyPlusClassSeats(int planeId){
   int row,number_of_economy_plus_rows, number_of_economy_class_rows, number_of_first_class_rows, planeIndex, totalAvailableSeats, column;
    for (int i = 0; i < Fleet::storagePlanes.size(); i++)
    {
    	if(Fleet::storagePlanes[i].getPlaneNumber() == planeId)
    	{
    		planeIndex = i;
    		number_of_first_class_rows = Fleet::storagePlanes[i].get_number_of_first_class_rows();
    		number_of_economy_class_rows = Fleet::storagePlanes[i].get_number_of_economy_class_rows();
    		number_of_economy_plus_rows = Fleet::storagePlanes[i].get_number_of_economy_plus_rows();
    		column = Fleet::storagePlanes[i].get_column();
    		totalAvailableSeats = column * number_of_economy_plus_rows;
		    std::vector<string> seats= Fleet::storagePlanes[planeIndex].getPassengerSeats();
		    for (int i = 0; i < seats.size(); i++)
		    {
		    	// computes for 2A - type of seat
		        if(seats[i].length() == 2)
		        {
		            row = Fleet::utility.stringToInt(seats[i].substr(0,1));
		        }
				//computes for 23A - type
		        else if(seats[i].length() == 3)
		        {
		        	row = Fleet::utility.stringToInt(seats[i].substr(0,2));
		        }
		        // subtract the number of seats taken from the total possible seats
	            if((row > number_of_first_class_rows + number_of_economy_class_rows) && (row <= number_of_first_class_rows + number_of_economy_class_rows + number_of_economy_plus_rows))
	            {
	                totalAvailableSeats--;
	            }

		    }
    	}
    }
    return totalAvailableSeats;
}
void Fleet::addPlane(
	int column,
	int number_of_economy_class_rows,
	int number_of_economy_plus_rows,
	int number_of_first_class_rows ){
	
	NewPlane plane(
		column,
		number_of_economy_class_rows,
		number_of_economy_plus_rows,
		number_of_first_class_rows
	);
	Fleet::newPlanes.push_back(plane);
	Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes,"./utility/data/plane.txt");
}
void Fleet::addPassenger(int planeNumber, int passengerId, string seat){
	bool found = false;
	bool duplicatePassenger = false;
	bool duplicateSeat = false;
	cout << storagePlanes.size() << endl;
	for (int i = 0; i < Fleet::storagePlanes.size(); i++)
	{
		cout << Fleet::storagePlanes[i].getPlaneNumber() << " -- " << planeNumber << endl;
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
			break;
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
		Fleet::utility.writeFile(Fleet::storagePlanes, Fleet::newPlanes, "./utility/data/plane.txt");
	}
    
}

int Fleet::getMaxPlaneId(){
	int max = 0;
	for (int i = 0; i < Fleet::storagePlanes.size(); i++)
	{
		if(Fleet::storagePlanes[i].getPlaneNumber() > max)
		{
			max = Fleet::storagePlanes[i].getPlaneNumber();
		}
	}
	return max;
}

bool Fleet::plane(int planeId){
	bool found = false;
	for (int i = 0; i < Fleet::storagePlanes.size(); i++)
	{
		if(Fleet::storagePlanes[i].getPlaneNumber() == planeId)
		{
			found = true;
			break;
		}
	}
	return found;
}