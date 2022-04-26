///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Customer.h
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The specification file for the class Customer
/////////////////////////////////////////////////////////////////////////

#ifndef Customer_H
#define Customer_H

#include <ostream>
#include <string>
#include "OrderList.h"

using namespace std;

//////////
//
// Class: Customer
// 
// Description: 
// 
// Data Members:
// output op
// name
// address
// email
// orders
// 
// Member Functions:
// Customer (2)
// getOrders
// AddOrder
// UpdateOrders
// CancleOrders
// getCustomerName
// getAddress
// getEmail
// checkoutOrders
// overloaded == op
// overloaded != op
//
//////////

class Customer  {
        friend ostream& operator<<(ostream&, const Customer&);
    private:
        string name;
        string address;
        string email;
        OrderList orders;

    public:
        Customer();
        Customer(string, string, string, OrderList);
        OrderList getOrders();
        void AddOrder(Order);
        void UpdateOrders(string, int);
        void CancelOrder(string);
        string getCustomerName();
        string getAddress();
        string getEmail();
        double checkoutOrders();
        bool operator==(const Customer&) const;
        bool operator!=(const Customer&) const;
};

#endif
