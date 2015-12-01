#include <iostream>
#include "../../passengers/passenger/newPassenger.cpp"
#include "utilityPassenger.cpp"

int main() {


std::vector<StoragePassenger> storagePassengers;
std::vector<NewPassenger> newPassengers;
PassengerUtility test;

test.populateReadArray(storagePassengers);

NewPassenger test2("CHEAH","HON");
test2.addFlightNumber(1234);
test2.addPassengerSeat("5a");

test2.addFlightNumber(4566);
test2.addPassengerSeat("8a");

test2.addFlightNumber(8765);
test2.addPassengerSeat("9a");

newPassengers.push_back(test2);
test.writeFile(storagePassengers,newPassengers);

NewPassenger test3("cheah","hon");
test3.addFlightNumber(8999);
test3.addPassengerSeat("2b");

test3.addFlightNumber(9999);
test3.addPassengerSeat("5C");

newPassengers.push_back(test3);
test.writeFile(storagePassengers, newPassengers);





return 0;
	
}