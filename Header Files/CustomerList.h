#ifndef CustomerList_H
#define CustomerList_H

#include <iostream>
#include <string>
#include "linkedList.h"
#include "Customer.h"

using namespace std;

class CustomerList: public linkedListType<Customer> {
            friend ostream& operator<<(ostream&, const CustomerList&);
        public:
            void AddCustomer(Customer&);
            bool SearchCustomerByName(string) const;
            Customer getCustomerByName(string) const;
            void UpdateCustomer(Customer&);
            void UpdateDataFile(ofstream&);
};

#endif