#ifndef OrderList_H
#define OrderList_H

#include <iostream>
#include <string>
#include "linkedList.h"
#include "Order.h"

using namespace std;

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