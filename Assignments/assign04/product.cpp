/***************************************************************
 * File: product.cpp
 * Author: Bryan Calle
 * Purpose: Contains the method implementations for the Product class.
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
#include <string>
#include "product.h"
using namespace std;

// put your method bodies here
void Product::prompt()
{
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter description: ";
	getline(cin, description);
	cout << "Enter weight: ";
	cin >> weight;

	bool isBadPrice;
	do {
		isBadPrice = false;
		cout << "Enter price: ";
		cin >> basePrice;
		if (cin.fail() || basePrice < 0)
		{
			isBadPrice = true;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (isBadPrice);
}

float Product::getSalesTax() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	float tax = .06 * basePrice;
	return tax;
}

/*float Product::priceShipping() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	float heavy = weight;
	return heavy;
}*/
float Product::getShippingCost() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	float sCost = 2.00;
	float extra = 0;
	float lbs = weight;
	if (lbs > 5)
	{
		for (int i = 5; i < lbs; i++)
		{
			extra =+ extra + 0.10;
		}
		sCost =+ sCost + extra;
	}
	else
		sCost = 2.00;
	return sCost;
}

float Product::getTotalPrice() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	float tax = getSalesTax();
	float sCost = getShippingCost();
	float total = basePrice + tax + sCost;
	return total;
}

void Product::displayAP() const
{
	//float end = getTotalPrice();
	cout << name << " - " << "$" << basePrice << endl;
	cout << "(" << description << ")\n";
}

void Product::displayILI() const
{
	//float end = getTotalPrice();
	cout << "$" << basePrice << " - " << name << " - ";
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	float lbs = weight;
	cout << lbs << " lbs\n";
}

void Product::displayR() const
{
	float tax = getSalesTax();
	float sCost = getShippingCost();
	float end = getTotalPrice();
	cout << name << endl;
	cout << "  Price:" << setw(10) << "$" << setw(8) << basePrice << endl;
	cout << "  Sales tax:" << setw(6) << "$" << setw(8) << tax << endl;
	cout << "  Shipping cost:" << setw(2) << "$" << setw(8) << sCost << endl;
	cout << "  Total:" << setw(10) << "$" << setw(8) << end << endl;
}