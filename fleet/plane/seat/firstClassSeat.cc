#include <iostream>
#include <string>
#include "firstClassSeat.h"
using namespace std;

double FirstClassSeat::getPrice(){
	if(FirstClassSeat::daysLeft >= 30)
	{
		return FirstClassSeat::basePrice * 3;
	}
	if(FirstClassSeat::daysLeft >= 8 && FirstClassSeat::daysLeft < 30)
	{
		return FirstClassSeat::basePrice * 4;
	}
	if(FirstClassSeat::daysLeft >= 0 && FirstClassSeat::daysLeft < 8)
	{
		return FirstClassSeat::basePrice * 5;
	}
}

int FirstClassSeat::getDaysLeft(){
	return FirstClassSeat::daysLeft;
}