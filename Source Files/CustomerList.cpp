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
}

void CustomerList::AddCustomer(Customer& customer)
{
	linkedListType::insertLast(customer);
}

bool CustomerList::SearchCustomerByName(string name) const
{
	OrderList empty;
	Customer to_find = Customer(name,"","",empty);
	return linkedListType::search(to_find);
}

Customer CustomerList::getCustomerByName(string name) const
{
	linkedListIterator<Customer> i = linkedListIterator<Customer>(this->first);
	for (;i!=nullptr;++i)
	{
		if ((*i).getCustomerName() == name)
		{
			return *i;
		}
	}
	/* Are we supposed to throw if not found? */
}

void CustomerList::UpdateCustomer(Customer& updated)
{
	/* Assuming we're supposed to find the customer *
	 * by name and update that record with what     *
	 * we're passed in our argument.                */
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

void CustomerList::UpdateDataFile(ofstream&)
{

}
