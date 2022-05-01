///////////////////////////////////////////////////////////////////////
//
// Filename: Customer.cpp
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The implementation file for the class Customer
/////////////////////////////////////////////////////////////////////////

#include <ostream>
#include <string>
#include "OrderList.hpp"
#include "Customer.hpp"

using namespace std;


ostream& operator<<(ostream& out, const Customer& customer)
{
	out << "***************************************************************************************************\n";
	out << "Name:      " << customer.name << '\n';
	out << "Address:   " << customer.address << '\n';
	out << "Email:    " << customer.email << '\n';
	out << "------------ Book Orders -------------\n";
	out << customer.orders;
	out << "***************************************************************************************************\n";
	return out;
}

Customer::Customer()
{
	name = "";
	address = "";
	email = "";
	orders = OrderList();
}

Customer::Customer(string _name, string _address, string _email, OrderList _orders)
{
	name = _name;
	address = _address;
	email = _email;
	orders = _orders;
}

OrderList Customer::getOrders()
{
	return orders;
}

void Customer::AddOrder(Order order)
{
	orders.AddOrder(order);
}

void Customer::UpdateOrders(string title, int number)
{
	orders.UpdateOrder(title, number);
}

void Customer::CancelOrder(string title)
{
	orders.CancelOrder(title);
}

string Customer::getCustomerName()
{
	return name;
}

string Customer::getAddress()
{
	return address;
}

string Customer::getEmail()
{
	return email;
}

double Customer::checkoutOrders()
{
	double bookTotal;
	bookTotal = orders.CalculateSubtotal();
	return bookTotal;
}

bool Customer::operator==(const Customer& comp) const
{
	return name == comp.name;
}

bool Customer::operator!=(const Customer& comp) const
{
	return name != comp.name;
}
