///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: OrderList.h
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The specification file for the class OrderList
/////////////////////////////////////////////////////////////////////////

#ifndef OrderList_H
#define OrderList_H

#include <iostream>
#include <string>
#include "linkedList.h"
#include "Order.h"

using namespace std;

//////////
//
// Class: OrderList
// 
// Description: 
// 
// Data Members:
// output op
// 
// Member Functions:
// AddOrder
// UpdateOrder
// CancelOrder
// CalculateSubtotal
// UpdateDataFile
// SearchOrderList
//
//////////

class OrderList: public linkedListType<Order>   {
        friend ostream& operator<<(ostream&, const OrderList&);
    public:
        void AddOrder(Order&);
        void UpdateOrder(string, int);
        void CancelOrder(string);
        double CalculateSubtotal();
        void UpdateDataFile(ofstream&);

    private:
        void SearchOrderList(string title, bool& found, nodeType<Order>*& current) const;
};

#endif