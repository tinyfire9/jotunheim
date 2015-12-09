#include <iostream>
#include <string>
#include "airline.cpp"
#include "utility/client/validity.cpp"

using namespace std;



void divider();
void welcomeMessage();


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

int main()
{

   int choice;

  Airline airline;
  Fleet fleet;
  PassengerSCH passengers;
  FlightSchedule schedule;
  Validity validity;
    
    divider();
    welcomeMessage();
    divider();
   
    cout << "--------------------------------------WELCOME----------------------------\n\n";

    cout<< "1) add new plane" << endl;
    cout<< "2) add new passenger to a Flight" << endl;
    cout<< "3) add new passenger to a list" << endl;
    cout<< "4) add new flight" << endl;
    cout<< "5) transferPassengers " << endl;
    cout<< "6) Display passengers " << endl;
    cout<< "7) Display upcoming flights " << endl;
    cout<< "8) Exit " << endl;
    
    cout << "*   Select one of your desirable option" << endl;
    cout << "*   Enter either from 1 to 7 " << endl;
    divider();
    cout << " >> ";
    cin >> choice;
    
    if(validity.choiceValid(choice) == false)
    {
      cout << "You have entered an invalid choice! Please try again! \n";
    }
    
    if(validity.choiceValid(choice) == true)
    {
      
      
        
         if (choice == 1)
         {
          divider();
          int column;
          int numberOfFirstClassRows;
          int numberOfEconomyClassRows;
          int numberOfEconomyPlusRows;
          cout << "You have selected to add new plane! \n\n\n";
          cout << "Please enter the number of column! \n >>";
          cin >> column;
          cout << "Please enter the number of rows for first class \n >>";
          cin >> numberOfFirstClassRows;
          cout << "Please enter the number of rows for economy class \n >>";
          cin >> numberOfEconomyClassRows;
          cout << "Please enter the number of rows for economy plus class \n >>";
          cin >> numberOfEconomyPlusRows;
          divider();

          cout << "You have entered the following inputs for your new plane: \n";
          cout << "column = " << column << "\n";
          cout << "first class rows = " << numberOfFirstClassRows << "\n";
          cout << "economy class rows = " << numberOfEconomyClassRows << "\n";
          cout << "econom plus rows = " << numberOfEconomyPlusRows << "\n\n\n";

          airline.addNewPlane(column,numberOfFirstClassRows,numberOfEconomyClassRows,numberOfEconomyPlusRows);
 
          cout << "Your new plane has been created! \n\n";
         }

         if (choice == 2)
         {

          bool checkInput;
          checkInput = true;

          int flightNumber;
          int passengerId;
          string firstName;
          string lastName;

        
          cout << "You have selected to add new passenger to a flight ! \n\n\n";
          cout << "Please enter the flight number to add the new passenger in \n >>";
          cin >> flightNumber;
          cout << "Please enter the passenger ID to add in new flight \n >>";
          cin >> passengerId;
          cout << "Please enter the passenger first name without spaces in between\n >>";
          cin >> firstName;



          if (validity.stringValid(firstName) == false)
          {
          cout << "You have entered an invalid first name format! Please try again! \n";
          }

          else
          {


             cout << "Please enter the passenger last name without spaces in between\n >>";
             cin >> lastName;

           if (validity.stringValid(lastName) == false )
             {
               cout << "You have entered an invalid last name format! Please try again! \n";
             }

             
          }
          

          if(validity.stringValid(firstName) == true && validity.stringValid(lastName) == true)
          {

          divider();
          cout << "\n\nYou have entered the following inputs to add your new passenger to a flight ! \n\n\n";
          cout << "flight Number = " << flightNumber << "\n";
          cout << "passengerId = " << passengerId << "\n";
          cout << "first name = " << firstName << "\n";
          cout << "last name = " << lastName << "\n";

          airline.addNewPassengerToFlight(flightNumber,passengerId,firstName,lastName);
            


          }

          else
          {
            cout << "You have entered some incorrect format! Please try again!";
          }

         }
       }

       if(choice == 3)
       {

            string firstName;
            string lastName;

            cout << " You have selected to add passenger to a list! \n";

            cout << " Please enter the passenger first name \n >>";
            cin >> firstName;

            validity.stringValid(firstName);
           

            cout << " Please enter the passenger last name \n >>";
            cin >> lastName;
            validity.stringValid(lastName);
            


            if(validity.stringValid(firstName) == true && validity.stringValid(lastName) == true)
            {
              divider();
             cout << "\n\nYou have entered the following inputs to add a new passenger to a list ! \n\n\n";
             cout << "first name : " << firstName << "\n";
             cout << "last name: " << lastName << "\n";

             airline.addNewPassengerToList(firstName, lastName);

           }
           else
           {
            cout << "You have entered an invalid input or wrong format! Please try again!";
           }

       }

       if (choice == 4 )
       {

        int planeId;
        string origin;
        string destination;
        string departureDate;
        string departureTime;
        string returnDate;
        string returnTime;

         int month;
         int day;
         int year;

         int returnMonth;
         int returnDay;
         int returnYear;

         int returnHour;
         int returnMinute;

         int hour;
         int minute;


        cout << " You have selected to add new flight ! \n\n";
        cout << "Please enter the plane id to add the new flight ! \n >>";
        cin >> planeId;

        cout << "Please enter the origin \n >>";
        cin >> origin;

        cout << "Please enter the destination \n >>";
        cin >> destination;

        cout << "Please enter the departure month (0-12)\n >>";
        cin >> month;

        cout << "Please enter the departure day (1-30)\n >>";
        cin >> day;

        cout << "Please enter the departure year (xxxx)\n >>";
        cin >> year;

        validity.dateValid(month,day,year);

        if(validity.dateValid(month,day,year) == false)
        {
          departureDate =  to_string(month) + "/" + to_string(day) + "/"+ to_string(year);

        cout << "Please enter the departure hour (0-23)\n >>";
        cin >> hour;


        cout << "Please enter the departure minute (0-59)\n >>";
        cin >> minute;

        validity.timeValid(hour, minute);

        if(validity.timeValid(hour,minute) == false)
        {
          departureTime = to_string(hour) + ":" + to_string(minute);
          cout << "Please enter the return month (1-12)\n >>";
          cin >> returnMonth;

           cout << "Please enter the return day (1-30)\n >>";
           cin >> returnDay;

           cout << "Please enter the return year (xxxx > 2015)\n >>";
           cin >> returnYear;

           validity.returnDateValid(month,day,year,returnMonth,returnDay,returnYear);

           if (validity.returnDateValid(month,day,year,returnMonth,returnDay,returnYear) == false)
           {

              returnDate = to_string(returnMonth) + "/" + to_string(returnDay) + "/" + to_string(returnYear);
            

              cout << "Please enter the return hour (0-24) \n >>";
             cin >> returnHour ;

             cout << "Please enter the return minute (0-59)\n >>";
             cin >> returnMinute;

             validity.timeValid(returnHour,returnMinute);

             validity.returnTimeValid(hour,minute,returnHour,returnMinute); 



               if( validity.returnTimeValid(hour,minute,returnHour,returnMinute) == true )
                   {
                    returnTime = to_string(returnHour) + ":" + to_string(returnMinute);

                    cout << " You have entered the following inputs to add new flight ! \n\n\n";

                     cout << "Plane id = " <<planeId << endl;
                     cout << "Origin = " << origin << endl;
                     cout << "Destination = " << destination<< endl;
                     cout << " Departure date = " << departureDate << endl;
                     cout << " Departure Time = " << departureTime << endl;
                     cout << " Return date  = " <<returnDate << endl;
                     cout << " Return time = " << returnTime << endl;

                     airline.addNewFlight(planeId, origin, destination, departureDate, departureTime,returnDate,returnTime);

                   }
           }



 
        }

    }

}

  if(choice ==5)
  {
    int flightNumber;
    int currentPlaneId;
    int newPlaneId;
    divider();
    cout << "\n\n You have selected to transfer passengers! \n\n";

    cout << "Enter the flight number \n >>";
    cin >> flightNumber;

    cout << "Enter the current plane id you wish to transfer! \n >>";
    cin >> currentPlaneId;

    cout << "Enter the new plane id you wish to transfer! \n >>";
    cin >> newPlaneId;

    cout << " You have entered the following inputs to transfer passengers! \n\n";
    cout << " flight number = " << flightNumber << endl;
    cout << " current plane id = " << currentPlaneId << endl;
    cout << " new plane id = " << newPlaneId << endl;

    airline.transferPassengers(flightNumber,currentPlaneId,newPlaneId);




  }

 if (choice == 6)
    {
         int flightNumber;
         cout << " \n\nYou have selected to display the passengers ! \n";
         
         cout << " Enter the flight number to view the passengers \n >>"; 
         cin >> flightNumber;
         cout << " You have selected to view flight " << flightNumber << " passengers \n" ;
         airline.displayPassengers(flightNumber);

         divider();


    }

  if(choice == 7)
  {
    cout << "\n\nYou have selected to view the upcoming flights!! \n\n";
    airline.displayUpcomingFlights();
  }

  if(choice == 8)

  {
    divider();
    cout << "\n\n You have selected to exit the program!! THANK YOU FOR USING! \n\n";

    divider();
    exit(0);
  }

     




  return 0;
}