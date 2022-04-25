#ifndef Customer_H
#define Customer_H

#include <ostream>
#include <string>
#include "OrderList.h"

using namespace std;

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
        string getAddesress();
        string getEmail();
        double checkoutOrders();
        bool operator==(const Customer&) const;
        bool operator!=(const Customer&) const;
};

#endif
