#include "validity.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

Validity::Validity(){};

void Validity::choiceValid(){

	
bool checkInput;
checkInput = true;
 
    // for (int i =0; i < choice.size(); i++)
    //  {
	   //  if(!isalpha(choice[i]) || isspace(word[i]))
	   //  {
		  //   //cout << "WRONG INPUT";
		  //   checkInput = true;
	   //   }
	     
	   //   else
	   //   {
    //         checkInput = false;
           
	   //   }

    // }
	
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
    return checkInput;


    // if(checkInput ==true)
    // {
    // 	cout << "WRONG INPUT!";
    // }
    // if(checkInput == false)
    // {
    // 	cout << "CORRECT";
    }
     
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
                	cout << "WRONG INPUT!";
                	
                }
       }

       else
       {
       	checkInput = true;
       	cout << " WRONG INPUT";
       }

  }

  else 
  {
  	checkInput = true;
  	cout << " WRONG INPUT";
  }


}

bool timeValid(int hour, int minute){

 bool checkInput;
 checkInput = true;


}
