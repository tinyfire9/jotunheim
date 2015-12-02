
#include <iostream>
#include "fleet/fleet.cpp"
#include "fleet/fleet.h"


using namespace std;



int main()
{
	Fleet test;

	test.addPassenger(
       42,
       8999,
       "5a"
		);

	// PassengerSCH test2;

	// test2.addFlight(
	// 	2,
	// 	55,
	// 	"8A");
	
	return 0;
};