#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include "flightSchedule.h"
#include "./flight/newFlight.h"


FlightSchedule::FlightSchedule(){
	FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt"); // function to populate read array from storage flight and flight schedule text file
}

void FlightSchedule::addFlight( // function to add new flight
	int planeId, 
	string origin, 
	string destination,
	string departureDate,
	string departureTime,
	string returnDate,
	string returnTime ){
	
	NewFlight flight(
		planeId,
		origin,
		destination,
		departureDate,
		departureTime,
		returnDate,
		returnTime
	);
	FlightSchedule::newFlights.push_back(flight);
	FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt"); // function to write file into flight schedule
	FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt"); // function to populate read array from flightschedule text file
}

void FlightSchedule::addPassenger(int flightNumber, int passengerId, string firstName, string lastName){ // function to add new passenger
	bool found = false;
	bool duplicatePassenger = false;
	/*
	iterates through each flight checks if flight Number exits
		-if it finds the flight Number
			- check if the passenger is already in the flight
		-if the flightNumber is found and the passenger is not already in there
			- add passenger and it's name
			- write to txt file
			-fluse newFlights vector and reload data to storageFlights vector
	*/
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber)
		{
			found = true;
			std::vector<int> ids = FlightSchedule::storageFlights[i].getPassengerIds();
			for (int j = 0; j < ids.size(); j++)
			{
				if(ids[j] == passengerId)
				{
					// checks the duplicate passenger
					duplicatePassenger = true;
				}
			}
		}
		// check if there is duplicate passenger. If there is no duplicate then continute to add new passenger id and passenger name
		if((duplicatePassenger == false) && (found == true))
		{
			FlightSchedule::storageFlights[i].addPassengerId(passengerId); // stores the passenger id into the storage flights 
			FlightSchedule::storageFlights[i].addPassengerName(firstName + " " + lastName); // stores the passenger name into the storage flights
			break;
		}
	}

	if(found == false)
	{
		cout << "Entered flight number, " << flightNumber << ", does not exist! Please try again!" << endl;
	}
	else if(duplicatePassenger == true)
	{
		cout << "Passenger " << firstName << " " << lastName << ", with Id #" << passengerId << " is already in the flight !" << endl;
	}
	else
	{
		FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt");// function to write the storage flights into the flightSchedule text file 
		FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");//function to populate the read array from the flight schedule text file
	}
}

bool FlightSchedule::flight(int flightNumber, int planeId){ 
	// returns true if the flight# and planeId matchs a flight with the given planeId
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber && FlightSchedule::storageFlights[i].getPlaneId() == planeId)
		{
			return true;
		}
	}
	return false;
}

void FlightSchedule::displayPassengers(int flightNumber) // function to display passengers from the given flight number 
{
	bool found = false;
	vector<string> passengers;
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		if(FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber) // if flight number is found in the flight storage class, do this
		{
			found = true;
			passengers = FlightSchedule::storageFlights[i].getPassengerNames(); // gets the passenger names from the storage flights 
			for (int i = 0; i < passengers.size(); i++)
			{
				cout << passengers[i] << endl; // prints the list of passenger from the storage flights given a specific flight number
			}
			break;
		}
	}
	if(!found)
	{
		cout << "Sorry the entered flight number doesn't match any flight! Please try another one! " << endl;
	}
}

void FlightSchedule::displayUpcomingFlights(){ // Display all the upcoming flights from the local time
	time_t currentTime;
	struct tm *localTime;
	time( &currentTime );                   // Get the current time
	localTime = localtime( &currentTime );  // Convert the current time to the local time

	int currentHour = localTime->tm_hour;
	int currentMinute = localTime->tm_min;
	int currentYear =  localTime->tm_year + 1900 ;
	int currentMonth = localTime->tm_mon + 1;
	int currentDay = localTime->tm_mday;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Current time(MM/DD/YYYY, HH:MM) : " << currentMonth << "/" << currentDay << "/" << currentYear << ", " << currentHour << ":" << currentMinute << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "flightID" << setw(13) << "planeID" << setw(13) << "origin" << setw(13) // prints out the identification header with defined witdth
	 << "destination" << setw(13) << "depDate" << setw(13) << "depTime" << setw(13) 
	 << "retDate" << setw(13) << "retTime" << endl;
	/*
		for each flight, it gets the departure date and time
			- compares the current date&time against the departure date&time and
			 displays if the date&time is in the future
	*/
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		string departureDate = FlightSchedule::storageFlights[i].getDepartureDate();
		string departureTime = FlightSchedule::storageFlights[i].getDepartureTime();
		int hour = FlightSchedule::utility.stringToInt(departureTime.substr(0, 2));
		int minute = FlightSchedule::utility.stringToInt(departureTime.substr(3, 2));
		int month = FlightSchedule::utility.stringToInt(departureDate.substr(0, 2));
		int day = FlightSchedule::utility.stringToInt(departureDate.substr(3,2));
		int year = FlightSchedule::utility.stringToInt(departureDate.substr(6, 4));
		if(year == currentYear)
		{	
			if(month == currentMonth)
			{
				if(day == currentDay)
				{
					if(hour == currentHour)
					{
						if(minute >= currentMinute)
						{
							cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
							cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
							cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
							cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;							
						}
					}
					else if(hour > currentHour)
					{
						cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
						cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
						cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
						cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
					}
				}
				else if(day > currentDay) // checks the condition if day is more than or equal to current day
				{
					cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
					cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
					cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
					cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
				}
			}
			else if(month > currentMonth) // checks the condition if month is more than current month 
			{
				cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
				cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
				cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
				cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
			}
		}
		else if(year > currentYear) // checks the condition if the year is more than current year
		{
			cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
			cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
			cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
			cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
		}
	}
}

void FlightSchedule::displayPastFlights(){ // Display all the upcoming flights from the local time
	time_t currentTime;
	struct tm *localTime;
	time( &currentTime );                   // Get the current time
	localTime = localtime( &currentTime );  // Convert the current time to the local time

	int currentHour = localTime->tm_hour;
	int currentMinute = localTime->tm_min;
	int currentYear =  localTime->tm_year + 1900 ;
	int currentMonth = localTime->tm_mon + 1;
	int currentDay = localTime->tm_mday;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Current time(MM/DD/YYYY, HH:MM) : " << currentMonth << "/" << currentDay << "/" << currentYear << ", " << currentHour << ":" << currentMinute << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "flightID" << setw(13) << "planeID" << setw(13) << "origin" << setw(13) // prints out the identification header with defined witdth
	 << "destination" << setw(13) << "depDate" << setw(13) << "depTime" << setw(13) 
	 << "retDate" << setw(13) << "retTime" << endl;
	/*
		for each flight, it gets the departure date and time
			- compares the current date&time against the departure date&time and
			 displays if the date&time is in the past
	*/
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		string departureDate = FlightSchedule::storageFlights[i].getDepartureDate();
		string departureTime = FlightSchedule::storageFlights[i].getDepartureTime();
		int hour = FlightSchedule::utility.stringToInt(departureTime.substr(0, 2));
		int minute = FlightSchedule::utility.stringToInt(departureTime.substr(3, 2));
		int month = FlightSchedule::utility.stringToInt(departureDate.substr(0, 2));
		int day = FlightSchedule::utility.stringToInt(departureDate.substr(3,2));
		int year = FlightSchedule::utility.stringToInt(departureDate.substr(6, 4));
		if(year == currentYear)
		{	
			if(month == currentMonth)
			{
				if(day == currentDay)
				{
					if(hour == currentHour)
					{
						if(minute <= currentMinute)
						{
							cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
							cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
							cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
							cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;							
						}
					}
					else if(hour < currentHour)
					{
						cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
						cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
						cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
						cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
					}
				}
				else if(day < currentDay) // checks the condition if day is more than or equal to current day
				{
					cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
					cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
					cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
					cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
				}
			}
			else if(month < currentMonth) // checks the condition if month is more than current month 
			{
				cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
				cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
				cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
				cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
			}
		}
		else if(year < currentYear) // checks the condition if the year is more than current year
		{
			cout << FlightSchedule::storageFlights[i].getFlightNumber() << setw(15) << FlightSchedule::storageFlights[i].getPlaneId() << setw(15);
			cout << FlightSchedule::storageFlights[i].getOrigin() << setw(15) << FlightSchedule::storageFlights[i].getDestination() << setw(15);
			cout << FlightSchedule::storageFlights[i].getDepartureDate() << setw(15) << FlightSchedule::storageFlights[i].getDepartureTime() << setw(15);
			cout << FlightSchedule::storageFlights[i].getReturnDate() << setw(15) << FlightSchedule::storageFlights[i].getReturnTime() << endl;
		}
	}
}

void FlightSchedule::changePlane(int flightNumber, int currentPlaneId, int newPlaneId){ // function to change plane
	/*
		looks for a flight with the given flightnumber and planeId
	*/
	for (int i = 0; i < FlightSchedule::storageFlights.size(); i++)
	{
		/*
			if flight number if found, 
				- change the planeId
				- write to file
				- flush newFlights vector & re-load data to storageFlights vector
		*/
		if((FlightSchedule::storageFlights[i].getFlightNumber() == flightNumber) && (FlightSchedule::storageFlights[i].getPlaneId() == currentPlaneId))
		{
			FlightSchedule::storageFlights[i].setPlaneId(newPlaneId);
			FlightSchedule::utility.writeFile(FlightSchedule::storageFlights, FlightSchedule::newFlights, "./utility/data/flightSchedule.txt");// function to write to flight schedule text file
			FlightSchedule::utility.populateReadArray(FlightSchedule::storageFlights, "./utility/data/flightSchedule.txt");// function to pupulate read array from flight schedule text file
		}
	}

}