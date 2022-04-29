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


ostream& operator<<(ostream& out, const Customer& customer) {
    out << "***************************************************************************************************\n";
    out << "Name:      " << customer.name << '\n';
    out << "Address:   " << customer.address << '\n';
    cout << "Email:    " << customer.email << '\n';
    "------------ Book Orders -------------";
    cout << customer.orders;
}

Customer::Customer() {
    name = "";
    address = "";
    email = "";
    orders = OrderList();
}

Customer::Customer(string _name, string _address, string _email, OrderList _orders) {
    this->name = _name;
    this->address = _address;
    this->email = _email;
    this->orders = _orders;

}

OrderList Customer::getOrders() {
    return this->orders;
}

void Customer::AddOrder(Order order) {
	this->orders.AddOrder(order);
}

void Customer::UpdateOrders(string title, int number) {
    this->orders.UpdateOrder(title, number);
}

void Customer::CancelOrder(string title) {
    this->orders.CancelOrder(title);
}

string Customer::getCustomerName() {
    return this->name;
}

string Customer::getAddress() {
    return this->address;
}

string Customer::getEmail() {
    return this->email;
}

double Customer::checkoutOrders() {
    double total;
    double bookTotal;

    bookTotal = this->orders.CalculateSubtotal();
    total = bookTotal + (bookTotal * .07);
    return total;
}

bool Customer::operator==(const Customer& comp) const {
    return this->name == comp.name;
}

bool Customer::operator!=(const Customer& comp) const {
    return this->name != comp.name;
}
