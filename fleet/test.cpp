#include "fleet.cpp"

int main()
{
	Fleet plane;
    

 /*
	plane.addPlane(
		12,
		"5FirstclassRow",
		"7Economyclassrow",
		"8Economyplusrow"
		);
*/
	// plane.addPassenger(
	// 	42,
	// 	8999,
	// 	"5a");

	// plane.addPassenger(

	// 	48,
	// 	"5a");
	cout << "# of firstClassSeats " << plane.getAvailableFirstClassSeats(27) << endl;
	cout << "# of economyClassSeats " << plane.getAvailableEconomyClassSeats(27) << endl;
	cout << "# of economyPlusClassSeats " << plane.getAvailableEconomyPlusClassSeats(27) << endl;
	return 0;
}