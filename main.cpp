#include <iostream>
#include <string>
#include "airline.h"
#include "utility/client/validity.h"

using namespace std;



void divider();
void welcomeMessage();


void divider()
{
  cout << "---------------------------------------------------------------------------\n\n";
}


void welcomeMessage() // Welcome message
{  
     cout << "CS 3528: Data Structures and Algorithms \n" 
          << "Fall 2015  \n" 
          << "Program4/Final Group Project  \n"
          << "(Bemidji State University) \n"
          << "Author: Yohannes Seifu \n"
          << "        Teik (Silvester)\n";
}

int main()
{

   int choice;

  // classes objects
  Airline airline;
  Fleet fleet;
  PassengerSCH passengers;
  FlightSchedule schedule;
  Validity validity;
    
    divider();
    welcomeMessage();
    divider();
   
    cout << "--------------------------------------WELCOME----------------------------\n\n";
    // User option to pick from

    cout<< "1) add new plane" << endl;
    cout<< "2) add new passenger to a Flight" << endl;
    cout<< "3) add new passenger to a list" << endl;
    cout<< "4) add new flight" << endl;
    cout<< "5) transferPassengers " << endl;
    cout<< "6) Display passengers " << endl;
    cout<< "7) Display upcoming flights " << endl;
    cout<< "8) Exit " << endl;
    
    cout << "*   Select one of your desirable option" << endl;
    cout << "*   Enter either from 1 to 8 " << endl;
    divider();
    cout << " >> ";
    cin >> choice;
    
    if(validity.choiceValid(choice) == false)
    {
      cout << "You have entered an invalid choice! Please try again! \n";
    }
    
    if(validity.choiceValid(choice) == true)
    {
      
      
        
         if (choice == 1) // If the user picked to add new plane
         {
          divider();
          int column;
          int numberOfFirstClassRows;
          int numberOfEconomyClassRows;
          int numberOfEconomyPlusRows;
          cout << "You have selected to add new plane! \n\n\n";
          cout << "Please enter the number of column! \n >>";
          cin >> column;
          if(cin)
          {
              //If format is correct , do nothing 
          }
          else
          {
            divider();
            cout << "Wrong input column format! Please try again! \n"; // if format is wrong, prompt error message
            exit(0);
          }
  
          cout << "Please enter the number of rows for first class \n >>";
          cin >> numberOfFirstClassRows;
          if(cin)
          {
            //If format is correct , do nothing 
 
          }
          else
          {
            divider();
            cout << "Wrong input number of rows for first class format! Please try again! \n\n";
            exit(0);
          }

          cout << "Please enter the number of rows for economy class \n >>";
          cin >> numberOfEconomyClassRows;
          if(cin)
          {
            //If format is correct , do nothing 

          }
          else
          {
            divider();
            cout << "Wrong input number of rows for economy class format! Please try again! \n\n";
            exit(0);
          }
       
          cout << "Please enter the number of rows for economy plus class \n >>";
          cin >> numberOfEconomyPlusRows;
          if(cin)
          {
            //If format is correct , do nothing 

          }
          else
          {
            divider();
            cout << "Wrong input number of rows for economy plus format! Please try again! \n\n";
            exit(0);
          }
     
          divider();

          

          
         // if(validity.integerValid(column)== true && validity.integerValid(numberOfFirstClassRows) == true 
         //  && validity.integerValid(numberOfEconomyClassRows) == true && validity.integerValid(numberOfEconomyPlusRows)== true)
         // {
          cout << "You have entered the following inputs for your new plane: \n";
          cout << "column = " << column << "\n";
          cout << "first class rows = " << numberOfFirstClassRows << "\n";
          cout << "economy class rows = " << numberOfEconomyClassRows << "\n";
          cout << "econom plus rows = " << numberOfEconomyPlusRows << "\n\n\n";
           //Creates the new plane with their specific number of seats
          airline.addNewPlane(column,numberOfFirstClassRows,numberOfEconomyClassRows,numberOfEconomyPlusRows);
          cout << "Your new plane has been created! \n\n";

         //}

         // if(validity.integerValid(column)== false ||validity.integerValid(numberOfFirstClassRows) == false 
         //  || validity.integerValid(numberOfEconomyClassRows) == false || validity.integerValid(numberOfEconomyPlusRows) == false)
         // {}
          
         
 
          
         }

         if (choice == 2)// If the user picked to add new passenger into flight
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

          if(cin)
          {

          }
          else
          {
            cout << "You have entered an invalid flight number format! Please try again! \n\n";
            exit(0);
          }
          cout << "Please enter the passenger ID to add in new flight \n >>";
          cin >> passengerId;
          if(cin)
          {

          }
          else
          {
            cout << "You have entered an invalid flight number format! Please try again! \n\n";
            exit(0);
          }
          cout << "Please enter the passenger first name without spaces in between\n >>";
          cin >> firstName;
               if(cin)
                {

                }
                else
               {
                cout << "You have entered an invalid first name format! Please try again! \n\n";
                exit(0);
                }



          if (validity.stringValid(firstName) == false) // checks if user entered the correct name format .
          {
          cout << "You have entered an invalid first name format! Please try again! \n";
          }

          else
          {


             cout << "Please enter the passenger last name without spaces in between\n >>";
             cin >> lastName;
             if(cin)
                {

                }
               else
                 {
                 cout << "You have entered an invalid last name format! Please try again! \n\n";
                 exit(0);
                 }

           if (validity.stringValid(lastName) == false )// checks if user entered the correct name format .
             {
               cout << "You have entered an invalid last name format! Please try again! \n";
             }

             
          }
          

          if(validity.stringValid(firstName) == true && validity.stringValid(lastName) == true)// If format conditions are met
          {

          divider();
          //Prints out the user input
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

       if(choice == 3) // if the user pick to add passenger to a list
       {

            string firstName;
            string lastName;

            cout << " You have selected to add passenger to a list! \n";

            cout << " Please enter the passenger first name \n >>";
            cin >> firstName;

            validity.stringValid(firstName); // validates the user input first name 
           

            cout << " Please enter the passenger last name \n >>"; // validates the user input last name
            cin >> lastName;
            validity.stringValid(lastName);
            


            if(validity.stringValid(firstName) == true && validity.stringValid(lastName) == true)
            {
              divider();
             cout << "\n\nYou have entered the following inputs to add a new passenger to a list ! \n\n\n";
             cout << "first name : " << firstName << "\n";
             cout << "last name: " << lastName << "\n";

             airline.addNewPassengerToList(firstName, lastName); // adds the user input for new passenger into the list

           }
           else
           {
            cout << "You have entered an invalid input or wrong format! Please try again!";
           }

       }

       if (choice == 4 ) // if the user select to add new flight
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

         string stringMonth ;
         string stringDay;

         string stringMinute;
         string stringHour;

         string stringReturnHour;
         string stringReturnMinute;

         string stringReturnMonth;
         string stringReturnDay;


        cout << " You have selected to add new flight ! \n\n";
        cout << "Please enter the plane id to add the new flight ! \n >>";
        cin >> planeId;

        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format for plane id! Please try again! \n\n";
          exit(0);
        }

        cout << "Please enter the origin \n >>";
        cin >> origin;
        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format! for origin Please try again! \n\n";
          exit(0);
        }

        cout << "Please enter the destination \n >>";
        cin >> destination;
        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format for destination! Please try again! \n\n";
          exit(0);
        }

        cout << "Please enter the departure month (0-12)\n >>";
        cin >> month;
        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format for departure month! Please try again! \n\n";
          exit(0);
        }

        cout << "Please enter the departure day (1-30)\n >>";
        cin >> day;
        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format for departure day! Please try again! \n\n";
          exit(0);
        }

        cout << "Please enter the departure year (xxxx)\n >>";
        cin >> year;
        if(cin)
        {

        }
        else
        {
          cout << "Wrong input format for departure year! Please try again! \n\n";
          exit(0);
        }

        validity.dateValid(month,day,year); // validates the user input for date, month and year.

        if(validity.dateValid(month,day,year) == false) // checks the condition of user input and convert the month and year format to appropriate format
        {
          if  (month < 10 && day < 10)

          {
            
            stringMonth = "0" + to_string(month);
            stringDay = "0" + to_string(day);
            departureDate = stringMonth + "/" + stringDay + "/" + to_string(year); // if month and day is less than 10, then add a 0 in front 
 
          }

          else if( month < 10 && day > 10)

          {
            stringMonth = "0" + to_string(month);
            departureDate = stringMonth + "/" + to_string(day) + "/" + to_string(year); // if month is less than 10, add a 0 infront


          }

          else if (month > 10 && day < 10) 
          {
            stringDay = "0" + to_string(day);
            departureDate = to_string(month) + "/" + stringDay + "/" + to_string(year);// if day is less than 10, add a 0 infront           

          }

          else if (month > 9 && day > 9) // if month and day is more than 9
          {

            departureDate =  to_string(month) + "/" + to_string(day) + "/"+ to_string(year);

          }

        cout << "Please enter the departure hour (0-23)\n >>";
        cin >> hour;


        cout << "Please enter the departure minute (0-59)\n >>";
        cin >> minute;

        validity.timeValid(hour, minute); // validates the hour and time  in 24 hour format and 60 minute format

        if(validity.timeValid(hour,minute) == false)
        {

          if (hour < 10 && minute > 9)
          {
            stringHour = "0" + to_string(hour);
            departureTime = stringHour + ":" + to_string(minute); // if hour is less than 10, add a 0 infront

          }

          else if (hour > 9 && minute < 10)
          {
            stringMinute = "0" + to_string(minute);
            departureTime = to_string(hour) + ":" + stringMinute; // if minute is less than 10, add a 0 infront
          }

          else if (hour < 10 && minute < 10) // if hour  and mintue is less than 10, add a 0 infront for both of them
          {
            stringHour = "0" + to_string(hour);
            stringMinute = "0" + to_string(minute);

            departureTime = stringHour + ":" + stringMinute;
          }

          else if (hour > 9 && minute > 9) // if hour and minute is more than 9, just assign them to departureTime string.

          {
            departureTime = to_string(hour) + ":" + to_string(minute);

          }

          cout << "Please enter the return month (1-12)\n >>";
          cin >> returnMonth;

           cout << "Please enter the return day (1-30)\n >>";
           cin >> returnDay;

           cout << "Please enter the return year (xxxx > 2015)\n >>";
           cin >> returnYear;

           validity.returnDateValid(month,day,year,returnMonth,returnDay,returnYear);// validates the return month,day and year

           if (validity.returnDateValid(month,day,year,returnMonth,returnDay,returnYear) == false)
           {


              if (returnMonth > 9 && returnDay > 9)
              {
                returnDate = to_string(returnMonth) + "/" + to_string(returnDay) + "/" + to_string(returnYear);

              }

              else if (returnMonth < 10 && returnDay < 10)
              {
                stringReturnMonth = "0" + to_string(returnMonth);
                stringReturnDay = "0" + to_string(returnDay);

                returnDate = stringReturnMonth + "/" + stringReturnDay + "/"+ to_string(returnYear);
              }

              else if (returnMonth < 10 && returnDay > 9)
              {
                stringReturnMonth = "0" + to_string(returnMonth);
                returnDate = stringReturnMonth + "/" + to_string(returnDay) + to_string(returnYear);
              }

              else if (returnMonth > 9 && returnDay < 10)
              {
                stringReturnDay = "0" + to_string(returnDay);
                returnDate = to_string(returnMonth) + "/" + stringReturnDay + "/" + to_string(returnYear);
              }
                    

              cout << "Please enter the return hour (0-24) \n >>";
             cin >> returnHour ;

             cout << "Please enter the return minute (0-59)\n >>";
             cin >> returnMinute;



             validity.timeValid(returnHour,returnMinute); //validates the time format (24 hour and 60 minute)

             validity.returnTimeValid(hour,minute,returnHour,returnMinute); //validates the return time format with departure time.



               if( validity.returnTimeValid(hour,minute,returnHour,returnMinute) == true )// if validation is true, convert them to their appropriate format
                   {

                    if(returnHour > 9 && returnMinute > 9) // if return hour and return minute is more than 9, just assign it to return time 
                    {
                      returnTime = to_string(returnHour) + ":" + to_string(returnMinute);

                    }

                    else if(returnHour < 10 && returnMinute < 10) // if return hour and return minute is less than 10, add a zero in front
                    {
                      stringReturnMinute = "0" + to_string(returnMinute);
                      stringReturnHour = "0" + to_string(returnHour);

                      returnTime = stringReturnHour + ":"+ stringReturnMinute;
                    }

                    else if (returnHour < 10 && returnMinute > 9) // if return hour is less than 10, add a 0 in front.
                    {
                      stringReturnHour = "0" + to_string(returnHour);
                      returnTime = stringReturnHour + ":" + to_string(returnMinute);
                    }

                    else if (returnHour > 9 && returnMinute < 10) //if return minute is less than 10, add a 0 in front
                    {
                      stringReturnMinute = "0" + to_string(returnMinute);
                      returnTime = to_string(returnHour) + ":" + stringReturnMinute;
                    }


                    cout << " You have entered the following inputs to add new flight ! \n\n\n";// prints the user input

                     cout << "Plane id = " <<planeId << endl;
                     cout << "Origin = " << origin << endl;
                     cout << "Destination = " << destination<< endl;
                     cout << "Departure date = " << departureDate << endl;
                     cout << "Departure Time = " << departureTime << endl;
                     cout << "Return date  = " <<returnDate << endl;
                     cout << "Return time = " << returnTime << endl;
                     
                     //Adds the user input into the addNewFlight method to add a new flight.
                     airline.addNewFlight(planeId, origin, destination, departureDate, departureTime,returnDate,returnTime);

                   }
           }



 
        }

    }

}

  if(choice ==5) // if user select to transfer passengers!
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

    airline.transferPassengers(flightNumber,currentPlaneId,newPlaneId); // validates the transfered passengers


  }

 if (choice == 6) // if user select to display the passengers on that flight
    {
         int flightNumber;
         cout << " \n\nYou have selected to display the passengers ! \n";
         
         cout << " Enter the flight number to view the passengers \n >>"; 
         cin >> flightNumber;
         cout << " You have selected to view flight " << flightNumber << " passengers \n" ;
         airline.displayPassengers(flightNumber);

         divider();


    }

  if(choice == 7) // if the user select to view the upcoming flights
  {
    cout << "\n\nYou have selected to view the upcoming flights!! \n\n";
    airline.displayUpcomingFlights();
  }

  if(choice == 8)// if the user select to exit the program

  {
    divider(); 
    cout << "\n\n You have selected to exit the program!! THANK YOU FOR USING! \n\n";

    divider();
    exit(0);
  }

     




  return 0;
}