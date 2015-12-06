#include <iostream>
#include <string>

using namespace std;

#ifndef VALIDITY
#define VALIDITY


class Validity
{

public:
	Validity();
	void choiceValid();
	void stringValid(string word);
	//string removeSpaces(string input);
	void dateValid(int month, int day, int year);
	void timeValid(int hour, int minute);
	void returnDateValid(int departureMonth, int departureDay,
		int departureYear, int returnMonth, int returnDay, int returnYear);
	void returnTimeValid(int departureHour, int depatureMinute,
		int returnHour, int returnMinute);
	void flightNumberValid(int flightNumber);
	void planeIdValid (int planeId);
	void numberOfRowsAndColumnsValid(int column, int firstRow, int economyRow, int economyPlusRow);


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

