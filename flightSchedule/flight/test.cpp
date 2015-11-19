#include <iostream>
#include <string>
#include <ctime>
#include "flight.cpp"

int main()
{
	// time_t now = time(0);
	// char* dt = ctime(&now);
	// cout << dt << endl;
	Flight test(
		11, 
		22222, 
		"MSP", 
		"SFO" ,
		"dDate",
		"rTime",
		"rDate",
		"rTime"
	);
	cout << "getId -> " << test.getId() << endl;
	cout << "getFlightNumber -> " << test.getFlightNumber() << endl;
	test.setFlightNumber(999999);
	cout << "getFlightNumber -> " << test.getFlightNumber() << endl;
	cout << "getOrigin -> " << test.getOrigin() << endl;
	test.setOrigin("BJI");
	cout << "getOrigin -> " << test.getOrigin() << endl;
	cout << "getDestination -> " << test.getDestination() << endl;
	test.setDestination("JFK");
	cout << "getDestination -> " << test.getDestination() << endl;
	cout << "getDepartureDate -> " << test.getDepartureDate() << endl;
	test.setDepartureDate("depDDDD");
	cout << "getDepartureDate -> " << test.getDepartureDate() << endl;
	cout << "getDepartureTime -> " << test.getDepartureTime() << endl;
	test.setDepartureTime("depTTTT");
	cout << "getDepartureTime -> " << test.getDepartureTime() << endl;
	cout << "getReturnDate -> " << test.getReturnDate() << endl;
	test.setReturnDate("retDDDD");
	cout << "getReturnDate -> " << test.getReturnDate() << endl;
	cout << "getReturnTime -> " << test.getReturnTime() << endl;
	test.setReturnTime("retTTTT");
	cout << "getReturnTime -> " << test.getReturnTime() << endl;

	test.addPassengerId(11);
	test.addPassengerId(22);
	cout << "getPassengerIds -> " << test.getPassengerIds()[0] << endl;

	test.addPassengerName("Yohannes Seifu");
	test.addPassengerName("FN LN");
	cout << "getPassengerIds -> " << test.getPassengerNames()[0] << endl;
	return 0;
}