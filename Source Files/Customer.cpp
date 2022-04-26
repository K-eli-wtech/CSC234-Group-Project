#include <ostream>
#include <string>
#include "OrderList.h"
#include "Customer.h"

using namespace std;


ostream& operator<<(ostream&, const Customer&)  {

}

Customer::Customer()    {
    string name = "";
    string address = "";
    string email = "";

}

Customer::Customer(string name, string address, string email, OrderList)   {
    this->name;
    this->address;
    this->email;

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
