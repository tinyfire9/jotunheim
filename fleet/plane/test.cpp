#include "newPlane.cpp"
#include <iostream>

int main()
{
	NewPlane plane(10, 5, 6, 7);
	plane.addPassengerId(1);
	plane.addPassengerSeat("4B");

	plane.addPassengerId(4);
	plane.addPassengerSeat("3A");

	plane.addPassengerId(9);
	plane.addPassengerSeat("20A");

	cout << "size ID : " << plane.getPassengerIds().size() << endl;
	cout << "Data ID : " << plane.getPassengerIds()[0] << plane.getPassengerIds()[1] << plane.getPassengerIds()[2] << endl;
	// cout << "Test : " << plane.deletePassenger(4, "3A") << endl;
	cout << "Test : " << plane.deleteLastPassenger() << endl;
	cout << "Data ID : " << plane.getPassengerIds()[0] << plane.getPassengerIds()[1] << endl;
	cout << "size ST : " << plane.getPassengerSeats().size() << endl;
	return 0;
}