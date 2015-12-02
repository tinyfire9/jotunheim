#include "flightSchedule.cpp"

int main()
{
	FlightSchedule schedule;

	// schedule.addFlight(
	// 	123,
	// 	"BJI",
	// 	"CHO",
	// 	"Jan_12",
	// 	"1:OOPM",
	// 	"Jan_13",
	// 	"6:00PM");
	schedule.addPassenger(40, 112233, "slimfire", "seifu");
	schedule.addPassenger(1000, 112233, "slimfire", "seifu");
	schedule.addPassenger(40, 112233, "slimfire", "seifu");
	return 0;
}