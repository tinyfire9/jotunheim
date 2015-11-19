#include <iostream>
#include <string>
#include "passenger.cpp"
using namespace std;

int main()
{
	Passenger test("Yohannes", "Seifu", "2A", 23);
	cout << "getId -> " << test.getId() << endl;
	cout << "getFirstName -> " << test.getFirstName() << endl;
	test.setFirstName("slimfire");
	cout << "getFirstName -> " << test.getFirstName() << endl;
	cout << "getLastName -> " << test.getLastName() << endl;
	test.setLastName("test");
	cout << "getLastName -> " << test.getLastName() << endl;
	cout << "getSeatNumber -> " << test.getSeatNumber() << endl;
	test.setSeatNumber("6D");
	cout << "getSeatNumber -> " << test.getSeatNumber() << endl;
	cout << "getFlightNumbers -> " << test.getFlightNumbers()[0] << endl;
	test.addFlightNumber(8988);
	cout << "getFlightNumbers[0] -> " << test.getFlightNumbers()[0] << endl;
	cout << "getFlightNumbers[1] -> " << test.getFlightNumbers()[1] << endl;

	return 0;
}