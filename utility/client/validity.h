#include <iostream>
#include <string>
#include <../airline.h>

using namespace std;

#ifndef VALIDITY
#define VALIDITY


class Validity
{

public:
	Validity();
	bool choiceValid(int choice);
	bool stringValid(string word);
	//string removeSpaces(string input);
	bool dateValid(int month, int day, int year);
	bool timeValid(int hour, int minute);
	bool returnDateValid(int departureMonth, int departureDay,
		int departureYear, int returnMonth, int returnDay, int returnYear);
	bool returnTimeValid(int departureHour, int depatureMinute,
		int returnHour, int returnMinute);
	bool passengerIdValid(int passengerId);
	bool flightNumberValid(int flightNumber);
	bool planeIdValid (int planeId);
	bool numberOfRowsAndColumnsValid(int column, int firstRow, int economyRow, int economyPlusRow);


private:

    string word;
	int choice;
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int departureMonth;
	int departureDay;
	int departureYear;
	int departureHour;
	int departureMinute;
	int returnHour;
	int returnMinute;
	int flightNumber;
	int planeId;
	int column;
	int firstRow;
	int economyRow;
	int economyPlusRow;


};




#endif

