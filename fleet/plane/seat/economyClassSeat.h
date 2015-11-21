/*
	A header on Economy class seats that inherits from Seat class. It's main task is to calculate price based on
	the number of days left and a given base price. 
*/
#include <iostream>
#include <string>
#include "seat.h"

#ifndef ECONOMY_CLASS_SEAT_H
#define ECONOMY_CLASS_SEAT_H

using namespace std;

class EconomyClassSeat: public Seat{
public:
	EconomyClassSeat(string number, double basePrice, int daysLeft):Seat(number){
		EconomyClassSeat::basePrice = basePrice;
		EconomyClassSeat::daysLeft = daysLeft;
	}

	//  Post-condition : returns actual price based on it's base price and days left
	double getPrice();

	//  Post-condition : returns an integer, the number of days left until departure
	int getDaysLeft();
private:
	double basePrice;
	int daysLeft;
};

#endif