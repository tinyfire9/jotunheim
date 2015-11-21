#include <iostream>
#include <string>
#include "seat.cc"
#include "firstClassSeat.cc"
#include "economyClassSeat.cc"
#include "economyPlusClassSeat.cc"

using namespace std;

int main(){
	FirstClassSeat firstClassSeat("3A", 300.99, 44);
	EconomyClassSeat economyClassSeat("6D", 80.00, 3);
	EconomyPlusClassSeat economyPlusClassSeat("4E", 100.00, 22, 300);

	cout << "firstClassSeat getPrice -> " << firstClassSeat.getPrice() << endl;
	cout << "economyClassSeat getPrice -> " << economyClassSeat.getPrice() << endl;
	cout << "economyPlusClassSeat getPrice -> " << economyPlusClassSeat.getPrice() << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "firstClassSeat getDaysLeft -> " << firstClassSeat.getDaysLeft() << endl;
	cout << "economyClassSeat getDaysLeft -> " << economyClassSeat.getDaysLeft() << endl;
	cout << "economyPlusClassSeat getDaysLeft -> " << economyPlusClassSeat.getDaysLeft() << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "firstClassSeat getPrice -> " << firstClassSeat.getPrice() << endl;
	cout << "economyClassSeat getPrice -> " << economyClassSeat.getPrice() << endl;
	cout << "economyPlusClassSeat getPrice -> " << economyPlusClassSeat.getPrice() << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "economyPlusClassSeat getMiles " << economyPlusClassSeat.getMiles() << endl;
	return 0;
}
