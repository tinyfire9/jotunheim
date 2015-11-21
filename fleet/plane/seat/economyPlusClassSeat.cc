#include <iostream>
#include <string>
#include "economyPlusClassSeat.h"
using namespace std;

double EconomyPlusClassSeat::getPrice(){
	double finalPrice = 0;
	if(EconomyPlusClassSeat::daysLeft >= 30)
	{
		finalPrice = EconomyPlusClassSeat::basePrice;
	}
	if(EconomyPlusClassSeat::daysLeft >= 8 && EconomyPlusClassSeat::daysLeft < 30)
	{
		finalPrice = EconomyPlusClassSeat::basePrice * 1.1;
	}
	if(EconomyPlusClassSeat::daysLeft >= 0 && EconomyPlusClassSeat::daysLeft < 8)
	{
		finalPrice = EconomyPlusClassSeat::basePrice * 1.2;
	}
	//Additional charge
	if(EconomyPlusClassSeat::miles < 800 && EconomyPlusClassSeat::daysLeft < 30)
	{
		finalPrice += 85; //75 for miles & 10 for time
	}
	else if(EconomyPlusClassSeat::miles >= 800 && EconomyPlusClassSeat::daysLeft < 30)
	{
		finalPrice += 135;
	}
	else if(EconomyPlusClassSeat::miles < 800 && EconomyPlusClassSeat::daysLeft >= 30)
	{
		finalPrice += 75;
	}
	else if(EconomyPlusClassSeat::miles >= 800 && EconomyPlusClassSeat::daysLeft >= 30)
	{
		finalPrice += 125;
	}
	return finalPrice;
}

int EconomyPlusClassSeat::getDaysLeft(){
	return daysLeft;
}

double EconomyPlusClassSeat::getMiles(){
	return EconomyPlusClassSeat::miles;
}