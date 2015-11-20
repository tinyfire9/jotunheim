/* 
 * File:   main.cpp
 * Author: Silvester
 *
 * Created on November 19, 2015, 9:14 PM
 */

#include <cstdlib>
#include "utility.h"
#include "utilityPlane.h"
#include <iomanip>
//#include "plane.h"

using namespace std;




void planeUtility::addPlane(string planeId,string status,int column,int firstClassRows,int economyRows,int economyPlusRows)
{
            cout << planeId << setw(10) ;
            cout << status << setw(5) ;
            cout << column << setw(5);
            cout << firstClassRows << setw(5);
            cout <<economyPlusRows << setw(5);
            cout << economyRows << setw(5);
            
            for (int i = 0 ; i < 5; i++)
            {
            planeIdData.push_back(planeId);
            cout << "value of vec " << i << " \n";
            
            }
           
            
            
    
              
            

            
           
    
};

void askQuestion(planeUtility& thePlaneUtility);

void askQuestion(planeUtility& thePlaneUtility)
{
    
   
    string input;
    string readyStatus ="READY";
    string notReadyStatus ="NOT AVAILABLE";
    int column;
    int firstclassrow;
    int economyplusclassrow;
    int economyclassrow;
    int planeId;
    
    cout << "Do you wish to add new plane? \n";
    cout << "Enter Y if you wish to add new plane \n";
    cin >> input;
    
    bool checkInput = true;
    while(checkInput)
    {
        if (input == "Y" )
        {
            cout << "Enter the column\n >>";
            cin >> column;
            cout << "Enter first class row \n >>";
            cin >> firstclassrow;
            cout << "Enter economy plus row \n >>";
            cin >> economyplusclassrow;
            cout <<"Enter economy class row \n >>";
            cin >> economyclassrow;
            thePlaneUtility.addPlane("XYZ",readyStatus,column,firstclassrow,economyplusclassrow,economyclassrow);
            //We are still missing the plane ID generator
          
            checkInput = false;
        }
           else
           checkInput = false;
    }
         
}

int main() {
    
    planeUtility ut;
    
    askQuestion(ut);
 
    return 0;
}

