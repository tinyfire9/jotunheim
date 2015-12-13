#include "validity.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

Validity::Validity(){};



bool Validity::choiceValid(int choice){ // checks user input selection from 1 - 8

  
bool checkInput;
checkInput = false;
 
    if (choice >= 1 && choice < 9) 
    {
      checkInput = true;
      //cout << " CORRECT";
    }
    else
    {
      checkInput = false;
    //cout <<" WRONG INPUT !";
    }
    return checkInput;
}

bool Validity::stringValid(string word){ // checks the string  format if it is valid


bool checkInput;
checkInput = false;

    for (int i =0; i < word.size(); i++)
     {
      if(!isalpha(word[i]) || isspace(word[i])) // checks if it is alphabet or there is space in between the string
      {
        checkInput = false;
        break;
       }
       
       else
       {
            checkInput = true;
           
       }
    }

    return checkInput;
    }
     


bool Validity::dateValid(int month, int day, int year){ // checks the user input date format

bool checkInput;
checkInput = true;

  if(month >= 1 && month <= 12)
  {
     checkInput = false;    
     if(day >= 1 && day <= 30)
       {
         
         checkInput = false;
         if(year >= 2015)
            
                {
                   checkInput = false;                             
                }
                else
                {
                  checkInput = true;
                  
                  cout << "WRONG YEAR INPUT! \n";
                  exit(0);                
                }
       }

       else
       {
        checkInput = true;
        
        cout << " WRONG  DAY INPUT! \n";
        exit(0);
       }
  }
     else 
    {
      checkInput = true;
      
       cout << " WRONG MONTH INPUT! \n";
       exit(0);
    }
    return checkInput;

}

bool Validity::timeValid(int hour, int minute){ // checks the user input time format 

  string stringHour;
  string stringMinute;

  stringHour = to_string(hour); // convert hour to string
  stringMinute = to_string(minute); // convert minute to string 

  bool checkInput;
  checkInput = true;

  for (int i =0; i < stringHour.size(); i++) // interates the string hour size to check if it is digit
  {
      if(!isdigit(stringHour[i]))
      {
        checkInput = false;
        
        cout << "Wrong hour input \n";
        exit(0);
        break;
        
      }
       

      else
       {

              for(int i =0; i < stringMinute.size(); i++)
             {
              
                   if(!isdigit(stringHour[i]))
                   {
                      checkInput = false;
                      
                      cout << "Wrong minute input \n";  
                      exit(0);          
                      break;
                      
                    }

                   else
                   {
                     checkInput = true;
                  }            
            }           
        }
  }

  if( checkInput == true )
    { 

              if (hour >= 0 && hour <= 23) // checks if the hour is more than or  equal to 0 or less than or equal to 23 
              {
                 checkInput = false;
                    if(minute >= 0 && minute <= 59) // checks if the minute is more than 0 or less than or equal to 59 
                    {
                     checkInput = false;
                     
                    }
                    else
                    {
                       checkInput = true;
                       
                       cout << " Wrong minute input !!! \n"; // prompt error message 
                       exit(0);
                     } 
                }            
               else
                  {
                      checkInput = true;
                      
                      cout <<" Wrong hour input \n"; // prompt error message
                      exit(0);
                 }
    }
   
  return checkInput;

}


bool Validity::returnDateValid(int departureMonth, int departureDay,
    int departureYear, int returnMonth, int returnDay, int returnYear) // checks the user input for return date 
{

  bool checkInput;
  checkInput = true;

  if (departureMonth >= 1 && departureMonth <= 12) // checks from 1 - 12 for departure month 
  {
     checkInput = false;

     if(departureDay >= 1 && departureDay <= 30) // checks from 1 - 30 for departure day 
     {
        checkInput = false;

               if(departureYear >= 2015) // checks if departure year is more than or equal to 2015
                {
                  checkInput = false;

                }

                 else
                {
                 checkInput = true;
                 
                 cout << "Wrong departure year input \n"; // prompt error message 
                 exit(0); // exit program 
                }

     }

    else
         {
          checkInput = true;
         
          cout <<"Wrong day input \n"; // prompt error message 
          exit(0); // exit program
         }

  }

  else
      {
        checkInput = true;
        
        cout <<"Wrong month input \n"; // prompt error message 
        exit(0); //exit program 
      }


  if (returnYear == departureYear)
  {
     checkInput = false;

           if(returnMonth >= departureMonth && returnMonth <= 12) // checks the return month so that it does not go below the departure month
           {       
                    checkInput = false; 

                    if(returnDay < 30 && returnDay > departureDay) // checks if return day is less than 30 and return day must be more than or equal to departure day
                    {
                     checkInput = false;

                    }

                    else
                    {
                     checkInput = true;
                     
                     cout << " Wrong Month! Must be more or equal \n";
                     exit(0);

                    }     

           }
      
            else
           {      
            checkInput = true;
            
            cout << "Wrong return day or must be equal or more than return day\n";
            exit(0);
           }
    
  }

  else if (returnYear > departureYear) // if return year is more than departure year then do the following conditions
      {
        checkInput = false;
         if( returnMonth > 0 && returnMonth <= 12) // checks the return month from 0 - 12 
         {
          checkInput = false;

               if (returnDay > 0 && returnDay <= 30)
               {
                 checkInput = false;
               }     

               else
               {

                cout << "Wrong return day input! Please try again! \n";
                exit(0);                   

               }

         }

         else
         {
          checkInput = true;
          cout << "Wrong month input! Please try again! \n";
          exit(0);
         }
      }

  return checkInput;
}

bool Validity::returnTimeValid(int departureHour, int departureMinute,
    int returnHour, int returnMinute) // checks the time valid format 
{
  bool checkInput;
  checkInput = true;

  string stringDepartureHour;
  string stringDepartureMinute;
  string stringReturnHour;
  string stringReturnMinute;

  stringDepartureHour = to_string(departureHour); // convert the departureHour variables to string to their appropriate format if less than 0
  stringDepartureMinute = to_string(departureMinute); // convert the departureHMinute variables to string to their appropriate format if less than 0
  stringReturnHour = to_string(returnHour); // convert the returnHour  variables to string to their appropriate format if less than 0
  stringReturnMinute = to_string(returnMinute);// convert the returnHour variables to string to their appropriate format if less than 0


for(int i = 0 ; i < stringDepartureHour.size(); i++)
{

   if(!isdigit(stringDepartureHour[i])) // checks if user input is digit 
   {
    checkInput = false;
    
    cout << " Departure is not a valid digit!";
    break;
   }

   else
   {
        checkInput = true;
        for(int i = 0; i < stringDepartureMinute.size(); i++)
        {
            if(!isdigit(stringDepartureMinute[i]))
            {
              checkInput = false;
             
              cout << " Departure minute is not a valid digit !";
              break;
            }

                 else
                 {
                   checkInput = true;
                       for(int i = 0; i < stringReturnHour.size();i++)
                      {
                        if(!isdigit(stringReturnHour[i]))
                        {
                            checkInput = false;
                  
                            cout << " Return date is not a valid digit!";
                            break;
                        }
                        

                        else
                        {
                                checkInput = true;
                                for(int i =0 ; i < stringReturnMinute.size();i++)
                                {
                                  if(!isdigit(stringReturnMinute[i]))
                                  {
                                    checkInput = false;
                                  
                                    cout << " Return Minute is not a valid digit! ";

                                    break;
                                  }

                                  else

                                  {
                                    checkInput = true;              
                                  }        
                                }
                         }
                      }
                   }
        }

   }

}

if(checkInput == true)
{
  if(departureHour >= 0 && departureHour <= 23) // checks if departureHour is more than 0 and less than 23
  {
        if(departureMinute >= 0 && departureMinute <= 59) // checks if departureMinute is more than or equal to 0 and less than or equal to 59
         {
            
             if(returnHour >= 0 && returnHour <= 23) // checks if return hour is more than or equal to 0 or less than or equal to 23
             {
                   checkInput = true;
                   if(returnMinute >= 0 && returnMinute <= 59)
                   {
                     checkInput = true;
                    }

                  else
                   {
                   checkInput = false;

                   cout << "Wrong return minute! \n";
                   exit(0);
                   }
             }

             else
             {
              checkInput = false;
             cout << "Wrong return hour! \n";
             exit(0);
             }

         }

         else
         {
            checkInput = false;
            cout << "Wrong departure minute! \n";
            exit(0);
         }
  }

  else
  {
    checkInput = false;
    cout << "Wrong departure hour! \n";
    exit(0);
  }
}


  return checkInput;
}

bool Validity::flightNumberValid(int flightNumber)
{


return 0;

}



















