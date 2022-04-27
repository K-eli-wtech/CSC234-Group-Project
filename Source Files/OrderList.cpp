///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: OrderList.cpp
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The implementation file for the class OrderList
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "linkedList.h"
#include "Order.h"
#include "OrderList.h"

using namespace std;

ostream& operator<<(ostream& out, const OrderList& oList)
{

}

void OrderList::AddOrder(Order& order)
{
	insertLast(order);
}

void OrderList::UpdateOrder(string title, int number)
{

}

void OrderList::CancelOrder(string title)
{

}

double OrderList::CalculateSubtotal()
{

}

void OrderList::UpdateDataFile(ofstream&)
{

}

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{

}
