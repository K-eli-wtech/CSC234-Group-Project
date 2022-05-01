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
#include <algorithm> 
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

    string filename = "BookOrders.txt"
    ifstream inFile;
    inFile.open(filename);

    while (!inFile) {
        cout << "Failed to find the default file, please input file name." << endl;
	getline(cin, filename);
        inFile.open(filename);
    }

    LoadCustomers(inFile, customers);
    inFile.close();

    while (1)
    {
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
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

void LoadCustomers(ifstream& inFile, CustomerList& customers) {
    // Put a try catch block for "customers loaded" output
    string line;
    getline(inFile, line);
    try
    {
        while (!inFile.eof()) {
            string name = "";
            string address = "";
            string email = "";
            string book = "";
            string cost = "";
            string quantity = "";
            OrderList orders;

            name = line;
            name.erase(0, 1);
            getline(inFile, address);
            getline(inFile, email);
            while (1) {
                getline(inFile, line);
                if (line[0] == '%' || inFile.eof())
                {
                    break;
                }
                book = line;
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
        cout << "All customers and orders are loaded." << endl;
    }
    catch (int)
    {
        cout << "Error Loading customers" << endl;
    }
}

bool is_numeric_string(string str)
{
    int i = 0;
    for (i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return str.length() > 0 ? true : false;
}

bool is_double_string(string str)
{
    bool seen_decimal = false;
    int i = 0;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '.' && !seen_decimal)
        {
            seen_decimal = true;
        }
        else if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return str.length() > 0 ? true : false;
}

int selectMenu() {
    string sel;
    cout << "Please select one of the following actions: " << endl;
    cout << "1: Place an order." << endl;
    cout << "2: Update an order." << endl;
    cout << "3: Cancel an order." << endl;
    cout << "4: Print all orders." << endl;
    cout << "5: Checkout Orders." << endl;
    cout << "6: Exit \n" << endl;
    getline(cin, sel);
    if (!is_numeric_string(sel))
    {
        return -1;
    }
    return stoi(sel);

}

void PlaceOrder(CustomerList& customers) {
    /* It is necessary to use getline() to read cin like the inFile, *
         * since we get the customer's name from cin, which is more than *
         * one word.    */
    // Changed it to cin because you can't add the order with price and inv as strings
    string name, b_title, address, email, loop = "YES";
    double b_price;
    int b_inv;

    while (loop == "YES" || loop == "Y") {
        cout << "Enter customer name: ";
        getline(cin, name);

        if (customers.SearchCustomerByName(name)) {
            Customer cust;
            cust = customers.getCustomerByName(name);
            cout << "Existing customer." << endl;
            cout << "Enter the book title: ";
            getline(cin, b_title);
            cout << "Enter the price of the book: ";
            cin >> b_price;
            cout << "Enter the number of books: ";
            cin >> b_inv;

            // This isn't adding orders for existing customers but it does work below in the else statement for new customers
            Order ord(b_title, b_price, b_inv);
            cust.AddOrder(ord);
            UpdateDataFile(customers);

            cout << "New order is added for customer " << cust.getCustomerName() << endl;
            cout << "\nPlace another order (y or n)? ";
            cin >> loop;
            transform(loop.begin(), loop.end(), loop.begin(), ::toupper);
            cin.ignore();
            
        }
        else {
            cout << "New Customer." << endl;
            cout << "Enter customer address: ";
            getline(cin, address);
            cout << "Enter customer email: ";
            getline(cin, email);
            cout << "Enter the book title: ";
            getline(cin, b_title);
            cout << "Enter the price of the book: ";
            cin >> b_price;
            cout << "Enter the number of books: ";
            cin >> b_inv;

            OrderList orders;
            Order ord(b_title, b_price, b_inv);
            orders.AddOrder(ord);

            Customer ncust(name, address, email, orders);
            customers.AddCustomer(ncust);
            UpdateDataFile(customers);

            cout << "New order is added for customer " << ncust.getCustomerName() << endl;
            cout << "\nPlace another order (y or n)? ";
            cin >> loop;
            transform(loop.begin(), loop.end(), loop.begin(), ::toupper);
            cin.ignore();
            
        }

        
    }
}

void UpdateOrder(CustomerList& customers) {
    string name, b_title;
    int b_inv;
    Customer cust;
    cout << "Enter customer name: ";
    getline(cin, name);

    if (customers.SearchCustomerByName(name)) {
        cust = customers.getCustomerByName(name);
        cout << "Enter the book title to be updated: ";
        getline(cin, b_title);
        cout << "Enter the number of book to be updated : ";
        cin >> b_inv;

        //OrderList::SearchOrderList() to retrieve order by name if this doesnt work
        cust.UpdateOrders(b_title, b_inv);
        UpdateDataFile(customers);
        cin.ignore();
    }
    else {
        cout << "Customer does not exist.\n" << endl;
        cin.ignore();
    }
}

void CancelOrder(CustomerList& customers) {
    string name, title;
    Customer cust;
    cout << "Enter customer name: ";
    getline(cin, name);
    cust = customers.getCustomerByName(name);
    OrderList orders;
    orders = cust.getOrders();
    string x = "";

    cout << "Enter the book title to be canceled: ";
    getline(cin, title);

    if (customers.SearchCustomerByName(name)) {
        if (x == "") {
            cust.CancelOrder(title);
            UpdateDataFile(customers);
            cout << "The order is canceled.";
        }
        else {
            cout << "Book not found";
        }
        cin.ignore();
    }
    else {
        cout << "Customer does not exist.\n" << endl;
        cin.ignore();
    }
}

void PrintOrders(CustomerList& customers) {
    cout << customers;
}

void CheckoutOrders(CustomerList& customers) {
    string name;
    Customer cust;
    double subTotal = 0;
    double total = 0;

    cout << "Enter customer name: ";
    getline(cin, name);
    cust = customers.getCustomerByName(name);
    subTotal = cust.checkoutOrders();
    total = subTotal + (subTotal * .07);


    cout << cust << endl;
    cout << "Subtotal:              $" << subTotal << '\n';
    cout << "Tax:                   $" << subTotal * .07 << '\n';
    cout << "Total payment:         $" << total << '\n';

}

void UpdateDataFile(CustomerList& customers) {
    CustomerList clist;
    clist = customers;
    ofstream inFile;
    inFile.open("BookOrders.txt");
    clist.UpdateDataFile(inFile);
}
