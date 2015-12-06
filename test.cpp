#include "airline.cpp"
#include <iostream>
#include <string>

int main()
{
	Airline test;
	cout << "maximum assigned plane id : " << test.getMaxId("plane") << endl;
	cout << "maximum assigned passenger id : " << test.getMaxId("passenger") << endl;
	cout << "maximum assigned flight id : " << test.getMaxId("flight") << endl;
}