/*
	A header on first class seats that inherits from Seat class. It's main task is to calculate price based on
	the number of days left and a given base price. 
*/
#include <iostream>
#include <string>
#include "seat.h"

#ifndef FIRST_CLASS_SEAT_H
#define FIRST_CLASS_SEAT_H

using namespace std;

class FirstClassSeat: public Seat{
public:
	// Instantiate with base price and days left until flight
	FirstClassSeat(string number, double basePrice, int daysLeft):Seat(number){
		FirstClassSeat::basePrice = basePrice;
		FirstClassSeat::daysLeft = daysLeft;
	}

	//  Post-condition : returns actual price based on it's base price and days left
	double getPrice();

	//  Post-condition : return an integer, the number of days left until departure
	int getDaysLeft();
private:
	double basePrice;
	int daysLeft;
};

#endif