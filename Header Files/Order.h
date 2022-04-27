///////////////////////////////////////////////////////////////////////
//
// Filename: Order.h
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The specification file for the class Order
/////////////////////////////////////////////////////////////////////////

#ifndef Order_H
#define Order_H

#include <iostream>
#include <string>

//////////
//
// Class: Order
//
// Description:
//
// Data Members:
// output op
// bookTitle
// unitPrice
// number
//
// Member Functions:
// Order (2)
// checkTitle
// setNumber
// getTitle
// getPrice
// getNumber
// overloaded == op
// overloaded != op
//
//////////

using namespace std;
class Order
{
	friend ostream& operator<<(ostream&, const Order&);
	private:
		string bookTitle;
		double unitPrice;
		int number;
	public:
		Order();
		Order(string, double, int);
		bool checkTitle(string name);
		double CalculatorCost();
		void setNumber(int);
		string getTitle();
		double getPrice();
		int getNumber();
		bool operator==(const Order&) const;
		bool operator!=(const Order&) const;
};

#endif
