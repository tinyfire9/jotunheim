#include <iostream>
#include <string>
#include "economyClassSeat.h"
using namespace std;

double EconomyClassSeat::getPrice(){
	if(EconomyClassSeat::daysLeft >= 30)
	{
		return EconomyClassSeat::basePrice;
	}
	if(EconomyClassSeat::daysLeft >= 8 && EconomyClassSeat::daysLeft < 30)
	{
		return EconomyClassSeat::basePrice * 1.1;
	}
	if(EconomyClassSeat::daysLeft >= 0 && EconomyClassSeat::daysLeft < 8)
	{
		return EconomyClassSeat::basePrice * 1.2;
	}
}

int EconomyClassSeat::getDaysLeft(){
	return daysLeft;
}
