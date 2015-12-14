#include <iostream>
#include <vector>
#include "../utility/fleet/utilityPlane.h"

class Fleet
{
public:
	Fleet();
    /*
    Pre-condition : expects planeNumber, passengerId, column, first class rows, economy class rows and economy plus class rows
    Post-condition : creats a new fleet object, 
                    adds the new fleet object to the current list of fleets, 
                    updates the current list of fleets to on the txt file and 
                    flushs the newPlanes vector and reload the data form the txt file
    */
	void addPassenger(int planeNumber, int passengerId, string seat);
    /*
    Pre-condition : expects planeNumber, passengerId and seat
    Post-condition : returns true if the planeNumber and passengerID matchs a plane with the given planeId
    */

	void addPlane(int column, int number_of_first_class_rows, int number_of_economy_class_rows, int number_of_economy_plus_rows);
    /*
    Pre-condition : expects columnm , #first class rows, #economy class rows, # conomy plus class rows
    Post-condition : if plane exist and is not already in,
                it adds the column, #first class rows, #economy class rows, #economy plus class rows
    */
    int getAvailableFirstClassSeats(int planeId);
    /*
    Pre-condition : expects planeId 
    Post-condition : returns the available first class seats.
    */
    int getAvailableEconomyClassSeats(int planeId);
     /*
    Pre-condition : expects planeId 
    Post-condition : returns the available economy class seats.
    */
    int getAvailableEconomyPlusClassSeats(int planeId);
     /*
    Pre-condition : expects planeId 
    Post-condition : returns the available economy plus class seats.
    */
    int getNumberOfFirstClassPassengers(int planeId);
     /*
    Pre-condition : expects planeId 
    Post-condition : returns the number of passengers on first class seats.
    */
    int getNumberOfEconomyClassPassengers(int planeId);
     /*
    Pre-condition : expects planeId 
    Post-condition : returns the number of passengers on economy class seats.
    */
    int getNumberOfEconomyPlusClassPassengers(int planeId);
     /*
    Pre-condition : expects planeId 
    Post-condition : returns the number of passengers on economy plus class seats.
    */
    int getMaxPlaneId();
    bool plane(int planeId);
    /*
    Pre-condition : expects planeId
    Post-condition : displays all the plane on the console
    */
    bool transferPassengers(int currentPlaneId, int newPlaneId);
    bool allPotentialSeatsAvailable(int currentPlaneId, int newPlaneId);
private:
	vector<StoragePlane> storagePlanes;
	vector<NewPlane> newPlanes;
	PlaneUtility utility;
};

