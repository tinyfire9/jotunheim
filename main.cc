#include <iostream>
#include <string>
#include "airline.cpp"

int number_of_economy_class_rows();
void divider();
void welcomeMessage();

using namespace std;

int main()
{
	Airline airline;
  divider();
  welcomeMessage();
  divider();
  int choice;

  cout<< "1) add new plane" << endl;
  cout<< "2) add new passenger to a Flight" << endl;
  cout<< "3) add new passenger to a list" << endl;
  cout<< "4) add new flight" << endl;
  cout<< "5) Display passengers " << endl;
  cout<< "6) Display upcoming flights " << endl;
  cout << " >> ";
  cin >> choice;
  
  std::vector<int> ;
  if( choice == 1)
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
    ///////////////////////////////////////////////////////////////
  }
  else if(choice == 2)
  {

  }

  // airline.addNewPlane();
  // airline.addNewFlight();
  //airline.addNewPassengerToFlight();
  // airline.addNewPassengerToList();
  // airline.displayPassenger();
  // airline.displayUpcomingFlights();

    // departureFunction();


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
  return rows;
}

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