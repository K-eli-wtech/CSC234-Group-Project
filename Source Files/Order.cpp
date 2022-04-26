#include <iostream>
#include <string>
#include "Order.h"

using namespace std;


ostream& operator<<(ostream&, const Order&) {

}

Order::Order()  {
    string book = "";
    double price = 0.0;
    int quantity = 0;
}

Order::Order(string book, double price, int quantity)   {
    bookTitle = book;
    unitPrice = price;
    number = quantity;

}

bool Order::checkTitle(string name) {

}

double Order::CalculatorCost()  {

}

void Order::setNumber(int quantity)  {
    number = quantity;
}

string Order::getTitle()    {
    return bookTitle;
}

double Order::getPrice()    {
    return unitPrice;
}

int Order::getNumber()  {
    return number;
}

bool Order::operator==(const Order&) const  {

}

bool Order::operator!=(const Order&) const  {
    
}