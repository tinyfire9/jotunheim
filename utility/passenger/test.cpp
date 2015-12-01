#include <iostream>
#include "../../passengers/passenger/newPassenger.cpp"
#include "passengerUtility.h"

int main ()
{
 
   std::vector<StoragePassenger> storagePassengers;
   std::vector<NewPassenger> newPassengers;
   PassengerUtility test;

   test.populateReadArray(storagePassengers);

 return 0;
}