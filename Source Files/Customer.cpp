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
#include "OrderList.h"
#include "Customer.h"

using namespace std;


ostream& operator<<(ostream& out, const Customer& customer)  {
	out << "***************************************************************************************************\n";
	out << "Name:      " << customer.name << '\n';
	out << "Address:   " << customer.address << '\n';
	cout << "Email:    " << customer.email << '\n';
	"------------ Book Orders -------------";
	/* Iterate thru & print off book orders */
}

Customer::Customer()    {
    string name = "";
    string address = "";
    string email = "";

}

Customer::Customer(string _name, string _address, string _email, OrderList)   {
    name = _name;
    address = _address;
    email = _email;

}

OrderList getOrders()   {

}

void Customer::AddOrder(Order)  {

}

void Customer::UpdateOrders(string, int)    {

}

void Customer::CancelOrder(string)  {

}

string Customer::getCustomerName()  {
    return name;
}

string Customer::getAddress() {
    return address;
}

string Customer::getEmail() {
    return email;
}

double Customer::checkoutOrders()   {

}

bool Customer::operator==(const Customer&) const    {

}

bool Customer::operator!=(const Customer&) const    {

}
