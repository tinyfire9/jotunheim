/*
	A header on Seat class. This class has a basic getter and setter on a seat number
*/
#include <iostream>
#include <string>

#ifndef SEAT_H
#define SEAT_H


using namespace std;

class Seat{
	public:
		// Instantiate data member seat number
		Seat(string number);

		// Post-condition : returns seat number of type string
		string getNumber();

		// Pre-condition : accepts a parameter, seat number, of type string
		// Post-condition : sets the data member, seat number, to a new one
		void setNumber(string number);

		// Post-condition : interface to be implemted by firstClass, economyClass 
		// and economyPlusClass seats
		virtual double getPrice() = 0;
	private:
		string number;
};

#endif