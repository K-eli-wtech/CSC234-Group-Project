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

Customer getCustomerByName(string)
{

}

void CustomerList::UpdateCustomer(Customer&)
{

}

void CustomerList::UpdateDataFile(ofstream&)
{

}
