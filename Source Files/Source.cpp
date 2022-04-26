#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "CustomerList.h"

using namespace std;

void LoadCustomers(ifstream&, CustomerList&);
int selectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDataFile(CustomerList&);

int main()  {
    cout << "Welcome to Wake Bookstore!" << endl;

    ifstream inFile;
    inFile.open("BookOrders.txt");
    
    if(!inFile) {
        string subFile;
        cout << "Failed to find the default file, please input file name." << endl;
        cin >> subFile;
        inFile.open(subFile);
    }

    int choice = selectMenu();

    switch (choice)
    {
    case 1:
        PlaceOrder();
        break;
    case 2:
        UpdateOrder();
        break;
    case 3:
        CancelOrder();
        break;
    case 4:
        PrintOrders();
        break;
    case 5:
        CheckoutOrders();
        break;
    case 6:
        cout << "Thank you for shopping at Wake Bookstore!" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}

void LoadCustomers(ifstream&, CustomerList&) {
    if () {
        cout << "All customers and orders are loaded." << endl;
    }
    else {
        cout << "Error: Issue loading customer data information." << endl;
    }
        
}

int selectMenu()    {
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

void PlaceOrder(CustomerList&)  {
    return true;
}

void UpdateOrder(CustomerList&) {
    return true;
}

void CancelOrder(CustomerList&) {
    return true;
}

void PrintOrders(CustomerList&) {
    return true;
}

void CheckoutOrders(CustomerList&)  {
    return true;
}

void UpdateDataFile(CustomerList&)  {
    return true;
}