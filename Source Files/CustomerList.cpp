///////////////////////////////////////////////////////////////////////
//
// Filename: CustomerList.cpp
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The implementation file for the class CustomerList
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "linkedList.h"
#include "Customer.h"
#include "CustomerList.h"

using namespace std;

ostream& operator<<(ostream& out, const CustomerList& customers)
{
	linkedListIterator<Customer> i = linkedListIterator<Customer>(customers.first);
	for (;i!=nullptr;++i)
	{
		out << *i;
	}
	return out;
}

void CustomerList::AddCustomer(Customer& customer)
{
	linkedListType::insertLast(customer);
}

bool CustomerList::SearchCustomerByName(string name) const
{
	nodeType<Customer> * node;
	for (node=this->first;node != nullptr;node=node->link)
	{
		if (node->info.getCustomerName() == name)
		{
			return true;
		}
	}
	return false;
}

Customer CustomerList::getCustomerByName(string name) const
{
	nodeType<Customer> * node;
	for (node=this->first;node != nullptr;node=node->link)
	{
		if (node->info.getCustomerName() == name)
		{
			return node->info;
		}
	}
	/* Are we supposed to throw if not found? */
	/* If we do nothing if not found, it causes a segfault */
	/* Paul: I think if it doesn't specify we should either have it send an error and recall the function or fail
	   the program gracefully */ 
}

void CustomerList::UpdateCustomer(Customer& updated)
{
	/* Assuming we're supposed to find the customer *
	 * by name and update that record with what     *
	 * we're passed in our argument.                */
	// Paul: That was how I understood it
	nodeType<Customer> * node;
	for (node=this->first;node != nullptr;node=node->link)
	{
		if (node->info == updated) {
			node->info = updated;
			return;
		}
	}
	/* Throw error if customer doesn't exist? Add to list? */
}

void CustomerList::UpdateDataFile(ofstream& out)
{
	linkedListIterator<Customer> i = linkedListIterator<Customer>(this->first);
	for (;i!=nullptr;++i)
	{
		out << '%' << (*i).getCustomerName() << '\n';
		out << (*i).getAddress() << '\n';
		out << (*i).getEmail() << '\n';
		(*i).getOrders().UpdateDataFile(out);
	}
}
