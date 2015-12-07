#include "validity.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

Validity::Validity(){};

bool Validity::choiceValid(int choice){

	
bool checkInput;
checkInput = false;
 
    if (choice >= 1 && choice <= 9)
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

bool Validity::stringValid(string word){


bool checkInput;
checkInput = false;

    for (int i =0; i < word.size(); i++)
     {
	    if(!isalpha(word[i]) || isspace(word[i]))
	    {
		    checkInput = false;
		    break;
	     }
	     
	     else
	     {
            checkInput = true;
           
	     }
    }

    // if(checkInput ==false)
    // {
    // 	cout << "WRONG INPUT!";
    // }
    // if(checkInput == true)
    // {
    // 	cout << "CORRECT";

    // }

    return checkInput;
    }
     


bool Validity::dateValid(int month, int day, int year){

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
                	//cout << "WRONG YEAR INPUT!";               	
                }
       }

       else
       {
       	checkInput = true;
       	//cout << " WRONG  DAY INPUT!";
       }
  }
     else 
    {
  	  checkInput = true;
  	   //cout << " WRONG MONTH INPUT!";
    }
    return checkInput;

}

bool Validity::timeValid(int hour, int minute){

  string stringHour;
  string stringMinute;

  stringHour = to_string(hour);
  stringMinute = to_string(minute);

  bool checkInput;
  checkInput = true;

  for (int i =0; i < stringHour.size(); i++)
  {
      if(!isdigit(stringHour[i]))
      {
        checkInput = false;
        return checkInput;
        break;
      }
       

      else
       {

              for(int i =0; i < stringMinute.size(); i++)
             {
              
                   if(!isdigit(stringHour[i]))
                   {
                      checkInput = false;
                      return checkInput;             
                      break;
                    }

                   else
                   {
                     checkInput = true;
                  }            
            }           
        }
  }

  if (hour >= 0 && hour <= 23)
  {
     checkInput = false;

        if(minute >= 0 && minute <= 59)
        {
         checkInput = false;
         //cout << "OK";
        }
        else
        {
           checkInput = true;
           //cout << " wrong minute";
         } 
  }
  else
  {
    checkInput = true;
    //cout <<" wrong hour";
  }

  return checkInput;

}
