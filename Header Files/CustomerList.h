///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: CustomerList.h
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The specification file for the class CustomerList
/////////////////////////////////////////////////////////////////////////

#ifndef CustomerList_H
#define CustomerList_H

#include <iostream>
#include <string>
#include "linkedList.h"
#include "Customer.h"

using namespace std;

//////////
//
// Class: CustomerList
// 
// Description: 
// 
// Data Members:
// output op
// 
// Member Functions:
// AddCustomer
// SearchCustomerByName
// getCustomerByName
// UpdateCustomer
// UpdateDataFile
//
//////////

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