/***************************************************************
 * File: product.h
 * Author: Bryan Calle
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
// put your class definition here

class Product
{
private:
	std::string name;
	float basePrice;
	float weight;
	std::string description;
public:
	void prompt();
	float getBasePrice() const {return basePrice;}
	float getSalesTax() const;
	float priceShipping() const;
	float getShippingCost() const;
	float getTotalPrice()const;
	void displayAP() const;
	void displayILI() const;
	void displayR() const;
};
#endif
