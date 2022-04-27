///////////////////////////////////////////////////////////////////////
//
// Filename: Order.cpp
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The implementation file for the class Order
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "Order.h"

using namespace std;


ostream& operator<<(ostream& out, const Order& order)
{
	out << "Title: " << setw(20) << order.bookTitle << "\n";
	out << "Unit Price: " << setw(20) << order.unitPrice << "\n";
	out << "Number: " << setw(20) << order.number << endl;
	return out;
}

Order::Order()
{
	string book = "";
	double price = 0.0;
	int quantity = 0;
}

Order::Order(string book, double price, int quantity)
{
	bookTitle = book;
	unitPrice = price;
	number = quantity;
}

bool Order::checkTitle(string name)
{
	return (bookTitle == name);
}

double Order::CalculatorCost()
{
	double cost = this->number + this->unitPrice;
	return cost;
}

void Order::setNumber(int quantity)
{
	number = quantity;
}

string Order::getTitle()
{
	return bookTitle;
}

double Order::getPrice()
{
	return unitPrice;
}

int Order::getNumber()
{
	return number;
}

bool Order::operator==(const Order& right) const
{
	return (
		bookTitle == right.bookTitle && unitPrice == right.unitPrice
		&& number == right.number
	);
}

bool Order::operator!=(const Order& right) const
{
	return (
		bookTitle != right.bookTitle || unitPrice || right.unitPrice
		|| number != right.number
	);
}
