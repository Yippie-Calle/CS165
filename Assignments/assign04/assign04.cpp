/***************************************************************
 * File: assign04.cpp
 * Author: Bryan Calle
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <cstdlib> 
#include <sstream>
#include <cstring>
#include "product.h"
using namespace std;

int main()
{
   // Declare your Product object here
	Product result;

   // Call your prompt function here
	result.prompt();


   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      // Call your display advertising profile function here
	   result.displayAP();
   }
   else if (choice == 2)
   {
      // Call your display inventory line item function here
	   result.displayILI();
   }
   else
   {
      // Call your display receipt function here
	   result.displayR();
   }

   return 0;
}
