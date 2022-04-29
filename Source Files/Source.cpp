///////////////////////////////////////////////////////////////////////
//
// Filename: Source.cpp
// Date: April 24, 2022
// Programmer: Paul Garland, Justin Bester, Kaleb White
//
// Description:
//  The main file for the program that has to do with the operations of the Wake Bookstore
//  which showcases linked lists and working together for a group project.
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "CustomerList.h"
#include "OrderList.h"
#include "linkedList.h"

using namespace std;

void LoadCustomers(ifstream&, CustomerList&);
int selectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDataFile(CustomerList&);

int main() {
    CustomerList customers;

    cout << "Welcome to Wake Bookstore!" << endl;

    ifstream inFile;
    inFile.open("BookOrders.txt");

    if (!inFile) {
        string subFile;
        cout << "Failed to find the default file, please input file name." << endl;
        cin >> subFile;
        inFile.open(subFile);
    } 
    
    LoadCustomers(inFile, customers);

    int choice = selectMenu();

    switch (choice)
    {
    case 1:
        PlaceOrder(customers);
        break;
    case 2:
        UpdateOrder(customers);
        break;
    case 3:
        CancelOrder(customers);
        break;
    case 4:
        PrintOrders(customers);
        break;
    case 5:
        CheckoutOrders(customers);
        break;
    case 6:
        cout << "Thank you for shopping at Wake Bookstore!" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}

void LoadCustomers(ifstream& inFile, CustomerList& customers) {
    // Put a try catch block for "customers loaded" output
    
    try
    {
    while (inFile) {
        string name = "";
        string address = "";
        string email = "";
        string book = "";
        string cost = "";
        string quantity = "";
        string line;
        OrderList orders;

        getline(inFile, name);
        name.erase(0,1);
        getline(inFile, address);
        getline(inFile, email);
        
        getline(inFile, line);
        while (line[0] != '%') {
            getline(inFile, book);
            getline(inFile, cost);
            double _cost = stod(cost);
            getline(inFile, quantity);
            int _quantity = stoi(quantity);

            Order order(book, _cost, _quantity);
            orders.AddOrder(order);
        }
        Customer customer(name, address, email, orders);
        customers.AddCustomer(customer);

    }
    cout << "Customers Loaded" << endl;
    }
    catch (int)
    {
        cout << "Error Loading customers" << endl;
    }
}


int selectMenu() {
    int select;
    cout << "Please select one of the following actions: " << endl;
    cout << "1: Place an order." << endl;
    cout << "2: Update an order." << endl;
    cout << "3: Cancel an order." << endl;
    cout << "4: Print all orders." << endl;
    cout << "5: Checkout Orders." << endl;
    cout << "6: Exit \n" << endl;
    cin >> select;
    return select;

}

void PlaceOrder(CustomerList& customers) {
    string name, b_title;
    double b_price;
    int b_inv;
    Customer cust;

    cout << "Enter customer name: " << endl;
    cin >> name;

    cust = customers.getCustomerByName(name);
    cout << "Enter the book title: ";
    cin >> b_title;
    cout << "\nEnter the price of the book: ";
    cin >> b_price; 
    cout << "\nEnter the number of books: ";
    cin >> b_inv;

    Order ord(b_title, b_price, b_inv);
    cust.AddOrder(ord);
    cout << "New order is added for customer " << cust.getCustomerName();
    
}

void UpdateOrder(CustomerList& customers) {
    string name, b_title;
    int b_inv;
    Customer cust;
    cout << "Enter customer name: " << endl;
    cin >> name;

    cust = customers.getCustomerByName(name);
    cout << "Enter the book title to be updated: ";
    cin >> b_title;
    cout << "\nEnter the number of book to be updated: ";
    cin >> b_inv;
    
    //OrderList::SearchOrderList() to retrieve order by name if this doesnt work
    cust.UpdateOrders(b_title, b_inv);
    
    
}

void CancelOrder(CustomerList& customers) {
    string name, title;
    Customer cust;
    cout << "Enter customer name: " << endl;
    cin >> name;
    cust = customers.getCustomerByName(name);

    cout << "Enter the book title to be canceled: ";
    cin >> title;

    cust.CancelOrder(title);
    
}

void PrintOrders(CustomerList& customers) {
}

void CheckoutOrders(CustomerList& customers) {
    string name;
    Customer cust;
    cout << "Enter customer name: " << endl;
    cin >> name;
    cust = customers.getCustomerByName(name);

    cout << cust << endl;

}

void UpdateDataFile(CustomerList& customers) {
}
