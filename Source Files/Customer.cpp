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

void Customer::AddOrder(Order) {

}

void Customer::UpdateOrders(string, int) {

}

void Customer::CancelOrder(string) {

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

}

bool Customer::operator==(const Customer& comp) const {
    return this->name == comp.name;
}

bool Customer::operator!=(const Customer& comp) const {
    return this->name != comp.name;
}
