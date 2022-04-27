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
#include <fstream>
#include <string>
#include "linkedList.h"
#include "Order.h"
#include "OrderList.h"

using namespace std;

ostream& operator<<(ostream& out, const OrderList& orders) 
{
    linkedListIterator<Order> i = linkedListIterator<Order>(orders.first);
	for (;i!=nullptr;++i)
	{
		out << *i;
	}
	return out;
}

void OrderList::AddOrder(Order& order)
{
	linkedListType::insertLast(order);
}

void OrderList::UpdateOrder(string title, int number)
{
    nodeType<Order> *node;
	for (node=this->first;node != nullptr;node=node->link)
	{
		if (node->info.getTitle() == title)	{
			node->info.setNumber(number);
		} else {
			cout << "Title could not be found." << endl;
		}
	}
}

void OrderList::CancelOrder(string title)
{
	nodeType<Order> *node;
	for (node=this->first;node!=nullptr;node=node->link)
	{
		if (node->info.getTitle() == title)	{
			linkedListType::deleteNode(node->info);
		}
	}
}

double OrderList::CalculateSubtotal()
{
	double subtotal;
	linkedListIterator<Order> i = linkedListIterator<Order>(this->first);
	for (;i!=nullptr;++i)
	{
		subtotal = subtotal + (*i).CalculatorCost();
	}
	return subtotal;
}

void OrderList::UpdateDataFile(ofstream& out)
{
    linkedListIterator<Order> i = linkedListIterator<Order>(this->first);
	for (;i!=nullptr;++i)
	{
		out << (*i).getTitle() << "\n";
		out << (*i).getPrice() << "\n";
		out << (*i).getNumber() << "\n";
	}
}

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{

}
