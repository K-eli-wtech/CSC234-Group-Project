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
	cout << customer.orders;
}

Customer::Customer()    {
    name = "";
    address = "";
    email = "";
    orders = OrderList();
}

Customer::Customer(string _name, string _address, string _email, OrderList _orders)   {
    name = _name;
    address = _address;
    email = _email;
    orders = _orders;

}

OrderList Customer::getOrders()   {
	return orders;
}

void Customer::AddOrder(Order order)  {
	orders.AddOrder(order);
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

bool Customer::operator==(const Customer& comp) const    {
	/* Correct if this is wrong, but I believe this *
	 * should return true if the names are equal    */
	return name == comp.name;
}

bool Customer::operator!=(const Customer& comp) const    {
	/* Same as == above, but != */
	return name != comp.name;
}
