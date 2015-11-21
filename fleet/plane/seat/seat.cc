#include <iostream>
#include <string>
#include "seat.h"

using namespace std;

Seat::Seat(string number){
	Seat::number = number;
}

string Seat::getNumber(){
	return Seat::number;
}

void Seat::setNumber(string number){
	Seat::number = number;
}