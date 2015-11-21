/*
	A header on Economy Plus class seats that inherits from Seat class. It's main task is to calculate price based on
	the number of days left and a given base price. 
*/
#include <iostream>
#include <string>
#include "seat.h"
#ifndef ECONOMY_PLUSCLASS_SEAT_H
#define ECONOMY_PLUSCLASS_SEAT_H

using namespace std;

class EconomyPlusClassSeat: public Seat{
public:
	//Instantiate class with seat number, base price, days left and number of miles
	EconomyPlusClassSeat(string number, double basePrice, int daysLeft, double miles): Seat(number){
		EconomyPlusClassSeat::basePrice = basePrice;
		EconomyPlusClassSeat::daysLeft = daysLeft;
		EconomyPlusClassSeat::miles = miles;
	}

	//  Post-condition : returns actual price based on it's base price and days left
	double getPrice();

	//  Post-condition : returns an integer, the number of days left until departure
	int getDaysLeft();

	//post-condition : returns a double, the miles of a flight
	double getMiles();
private:
	double basePrice;
	int daysLeft;
	double miles;
};

#endif