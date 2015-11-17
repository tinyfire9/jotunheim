#include<iostream>
#include<string>
using namespace std;

/*
	@TODO
		* document each method
*/
class Plane
{
	public:
		int getId();
		int getColumns();
		int getNumberOfEconomyClassRows();
		int getNumberOfEconomyPlusClassRows();
		int getNumberOfFirstClassRows();
		int setColumns();
		int setNumberOfEconomyClassRows();
		int setNumberOfEconomyPlusClassRows();
		int setNumberOfFirstClassRows();
	private:
		int id;
		int columns;
		int numberOfEconomyClassRows;
		int numberOfEconomyPlusClassRows;
		int numberOfFirstClassRows;
}