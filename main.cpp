#include <iostream>
#include <string>
#include "airline.cpp"

using namespace std;



void divider();
void welcomeMessage();
void addNewPlaneToFleet();
void addNewFlightToSchedule();
void addNewPassengerToFlight();
int departureFunction();
int returnFunction();
int timeFunction();
int number_of_first_class_rows();
int number_of_economy_class_rows();
int number_of_economy_plus_rows();

string removeSpaces(string input);





void divider()
{
	cout << "---------------------------------------------------------------------------\n\n";
}


void welcomeMessage()
{  
     cout << "CS 3528: Data Structures and Algorithms \n" 
          << "Fall 2014  \n" 
          << "Program4/Final Group Project  \n"
          << "(Bemidji State University) \n"
          << "Author: Yohannes Seifu \n"
          << "        Teik (Silvester)\n";
}

void addNewPlaneToFleet()
{

}

void addNewFlightToSchedule()
{

}

void addNewPassengerToFlight()
{


}

int departureFunction()
{
	int day;
    int month;
    int year;
    string depatureDate;

    string finalday;
    string finalmonth;
    string finalyear;

bool checkInput;
checkInput = true;
 while(checkInput)
 {
   
   cout << "Enter the departure day: (1 - 30) \n >>";
   cin >> day;
      if (day >= 1 && day <= 30) 
         {
            cout << "Enter the departure month: (1 - 12) \n >>";
            cin >> month;

            if(month >= 1 &&  month <= 12)
           {

	               cout << "Enter the departure year: (Example: 2018)\n >>";
                   cin >> year;
                   if(year >= 2015)
                   {
                   	checkInput = false;
                   }

                   else 
                   {
                   	cout << "You entered an invalid departure year! Please try again! \n";
                   	checkInput = true;
                   }
           } 
           else{
           	cout << "You entered an invalid departure month! Please try again! \n";
           	checkInput = true;}

         }
       else
       {
       	    cout << "You entered an invalid departure day! Please try again! \n";
         	checkInput = true;}
 } 

   if(day>=0 && day<10)
   {
     finalday = "0" + to_string(day);
     if(month >= 0 &&  month<10)
     {
     	finalmonth = "0" + to_string(month);
        finalyear = to_string(year);
     }

     depatureDate = finalday +"/"+ finalmonth + "/" + finalyear;
     cout << depatureDate << endl; 
   }

  

   

   return 0;

};

int returnFunction()
{
	int day;
    int month;
    int year;
    string returnDate;

bool checkInput;
checkInput = true;
 while(checkInput)
 {
   
   cout << "Enter the return day: \n >>";
   cin >> day;
      if (day >= 1 && day <= 30) 
         {
            cout << "Enter the return month: \n >>";
            cin >> month;

            if(month >= 1 &&  month <= 12)
           {

	               cout << "Enter the return year: \n >>";
                   cin >> year;
                   if(year >= 2015)
                   {
                   	checkInput = false;
                   }

                   else 
                   {
                   	cout << "You entered an invalid return year! Please try again! \n";
                   	checkInput = true;
                   }
           } 
           else{
           	cout << "You entered an invalid return month! Please try again! \n";
           	checkInput = true;}

         }
       else
       {
       	    cout << "You entered an invalid return day! Please try again! \n";
         	checkInput = true;}
 } 
   returnDate = to_string(day)+"/"+ to_string(month)+"/"+ to_string(year);

   cout << returnDate << endl;

   return 0;

};


int timeFunction()
{

int hour =0;
int minute =0;

string finalhour;
string finalminute;

string passengerTime;
    
    bool checkInput;
    checkInput = true;
    while(checkInput)
    {
         cout << "Enter the hour: (0 - 23) \n >> ";
         cin >> hour;
         if (hour <= 23 &&  hour >=0 )
         {
             cout << "Enter the minute: (0 - 59) \n >>" ;
             cin >> minute;
             if( minute >=0 && minute <= 59)
             {

             	checkInput = false;

             }
             else
             {
             	cout << "You entered an invalid minute! Please try again! \n";
             	checkInput = true;
             }


         }
         else
         {
         	cout << "You entered an invalid hour! Please try again! \n";
         	checkInput = true;
         }
    }

    if(hour <10 && hour >= 0)
    {
    	finalhour = "0" + to_string(hour);

    	if(minute <10 && minute >=0)
        {
    	     finalminute = "0" + to_string(hour);

    	     passengerTime = finalhour + ":" + finalminute ;
	
	         cout << passengerTime << endl;
         }
    }

    

    	//cout << passengerTime << endl;

	return 0;

}

string removeSpaces(string input)
{
  int length = input.length();
  for (int i = 0; i < length; i++) {
     if(input[i] == ' ')
     {
        input.erase(i, 1);
         length--;
         i--;
     }
  }
  return input;
}

void passengerNameFunction()
{
	char firstName[256];
    char lastName[256];

    string passengerName;

  

    cout << "Enter your first name: \n >> ";
    cin.getline(firstName,256);
    removeSpaces(firstName);


    cout << "Enter your last name: \n >> ";
    cin.getline(lastName,256);
    removeSpaces(lastName);

    passengerName = removeSpaces(firstName) + " " + removeSpaces(lastName);

    cout << passengerName << endl;

}

int number_of_first_class_rows()
{
	int rows;
	
    
    bool checkInput;
    checkInput = true;
    while(checkInput)
    {

      cout << "Enter the number of rows for first class: \n >>";
	  while(!(cin >> rows))
	  {
	  	cin.clear();
	  	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	  	cout << "Invalid input. Try again!" << endl;
	  	cout << "Enter the number of rows for first class: \n >>";
	  }
         if (rows >= 1)
        {
           cout << rows ;
      	   checkInput = false;
        }

        else
        {
      	cout << "You entered an invalid number of rows! Please try again! \n";
      	checkInput = true;
         }
      

    }
    return 0;

}

int number_of_economy_class_rows()
{
	int rows;
	
    
    bool checkInput;
    checkInput = true;
    while(checkInput)
    {

      cout << "Enter the number of rows for economy class: \n >>";
	  while(!(cin >> rows))
	  {
	  	cin.clear();
	  	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	  	cout << "Invalid input. Try again!" << endl;
	  	cout << "Enter the number of rows for economy class : \n >>";
	  }
         if (rows >= 1)
        {
           cout << rows ;
      	   checkInput = false;
        }

        else
        {
      	cout << "You entered an invalid number of rows! Please try again! \n";
      	checkInput = true;
         }
      

    }
    return 0;

}

int number_of_economy_plus_rows()
{
	int rows;
	
    
    bool checkInput;
    checkInput = true;
    while(checkInput)
    {

      cout << "Enter the number of rows for economy plus: \n >>";
	  while(!(cin >> rows))
	  {
	  	cin.clear();
	  	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	  	cout << "Invalid input. Try again!" << endl;
	  	cout << "Enter the number of rows for first class: \n >>";
	  }
         if (rows >= 1)
        {
           cout << rows ;
      	   checkInput = false;
        }

        else
        {
      	cout << "You entered an invalid number of rows! Please try again! \n";
      	checkInput = true;
         }
      

    }
    return 0;

}


int main()
{

	Airline airline;
	Fleet fleet;
	PassengerSCH passengers;
	FlightSchedule schedule;
    
    divider();
    welcomeMessage();
    divider();

    departureFunction();

    //timeFunction();

    //passengerNameFunction();

    //number_of_first_class_rows();

    //number_of_economy_class_rows();
 
    //number_of_economy_plus_rows();


	//airline.transferPassengers(0, 1, 1);


    //fleet.addPassenger(7,11,"5a");


	return 0;
}