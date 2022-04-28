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
        getline(inFile, address);
        getline(inFile, email);
        

        while (/*line doesnt start with '%'? */) {
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

        // I don't think this part is going to work but I'm trying to loop it if the line doesn't start with % for the next name so we can store the orders
        getline(inFile, line);
        if (line.find("%") != string::npos) {
            name = line;
            cout << "its a name" << endl;
            break;
        } else {
            book = line;
            getline(inFile, cost);
            getline(inFile, quantity);
            cout << book << "\n" << cost << "\n" << quantity << "\n" << endl;
        }

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
    cout << "Enter customer name: " << endl;

    if () {

    }
    else {
        cout << "Customer does not exist" << endl;
    }
}

void UpdateOrder(CustomerList& customers) {
    cout << "Enter customer name: " << endl;

    if () {

    }
    else {
        cout << "Customer does not exist" << endl;
    }
}

void CancelOrder(CustomerList& customers) {
    cout << "Enter customer name: " << endl;

    if () {

    }
    else {
        cout << "Customer does not exist" << endl;
    }
}

void PrintOrders(CustomerList& customers) {
}

void CheckoutOrders(CustomerList& customers) {
}

void UpdateDataFile(CustomerList& customers) {
}
