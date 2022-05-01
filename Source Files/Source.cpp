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

int main()
{
	CustomerList customers;

	cout << "Welcome to Wake Bookstore!" << endl;

	string filename = "BookOrders.txt";
	ifstream inFile;
	inFile.open(filename);

	while (!inFile)
	{
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
			UpdateDataFile(customers);
			break;
		case 2:
			UpdateOrder(customers);
			UpdateDataFile(customers);
			break;
		case 3:
			CancelOrder(customers);
			UpdateDataFile(customers);
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

void LoadCustomers(ifstream& inFile, CustomerList& customers)
{
	string line;
	getline(inFile, line);
	try
	{
		while (!inFile.eof())
		{
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
			while (1)
			{
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

int selectMenu()
{
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

void PlaceOrder(CustomerList& customers)
{
	string name, b_title, address, email, loop = "YES";
	string price, inv;
	double b_price;
	int b_inv;

	while (loop == "YES" || loop == "Y")
	{
		cout << "Enter customer name: ";
		getline(cin, name);

		if (customers.SearchCustomerByName(name))
		{
			Customer cust;
			cust = customers.getCustomerByName(name);
			cout << "Existing customer." << endl;
			cout << "Enter the book title: ";
			getline(cin, b_title);
			cout << "Enter the price of the book: ";
			getline(cin, price);
			while (!is_double_string(price))
			{
				cerr << "Invalid input!\n";
				cout << "Enter the price of the book: ";
				getline(cin, price);
			}
			b_price = stod(price);
			cout << "Enter the number of books: ";
			getline(cin, inv);
			while (!is_numeric_string(inv))
			{
				cerr << "Invalid input!\n";
				cout << "Enter the number of books: ";
				getline(cin, inv);
			}
			b_inv = stoi(inv);

			Order ord(b_title, b_price, b_inv);
			cust.AddOrder(ord);
			customers.UpdateCustomer(cust);

			cout << "New order is added for customer " << cust.getCustomerName() << endl;
			cout << "\nPlace another order (y or n)? ";
			getline(cin, loop);
			transform(loop.begin(), loop.end(), loop.begin(), ::toupper);

		}
		else
		{
			cout << "New Customer." << endl;
			cout << "Enter customer address: ";
			getline(cin, address);
			cout << "Enter customer email: ";
			getline(cin, email);
			cout << "Enter the book title: ";
			getline(cin, b_title);
			cout << "Enter the price of the book: ";
			getline(cin, price);
			while (!is_double_string(price))
			{
				cerr << "Invalid input!\n";
				cout << "Enter the price of the book: ";
				getline(cin, price);
			}
			b_price = stod(price);
			cout << "Enter the number of books: ";
			getline(cin, inv);
			while (!is_numeric_string(inv))
			{
				cerr << "Invalid input!\n";
				cout << "Enter the number of books: ";
				getline(cin, inv);
			}
			b_inv = stoi(inv);

			OrderList orders;
			Order ord(b_title, b_price, b_inv);
			orders.AddOrder(ord);
			Customer ncust(name, address, email, orders);
			customers.AddCustomer(ncust);

			cout << "New order is added for customer " << ncust.getCustomerName() << endl;
			cout << "\nPlace another order (y or n)? ";
			getline(cin, loop);
			transform(loop.begin(), loop.end(), loop.begin(), ::toupper);
		}
	}
}

void UpdateOrder(CustomerList& customers)
{
	string name, b_title, inv;
	int b_inv;
	Customer cust;
	cout << "Enter customer name: ";
	getline(cin, name);

	if (customers.SearchCustomerByName(name))
	{
		cust = customers.getCustomerByName(name);
		cout << "Enter the book title to be updated: ";
		getline(cin, b_title);
		cout << "Enter the number of book to be updated : ";
		getline(cin, inv);
		while (!is_numeric_string(inv))
		{
			cerr << "Invalid input!\n";
			cout << "Enter the number of books: ";
			getline(cin, inv);
		}
		b_inv = stoi(inv);

		cust.UpdateOrders(b_title, b_inv);
		customers.UpdateCustomer(cust);
	}
	else
	{
		cout << "Customer does not exist.\n" << endl;
	}
}

void CancelOrder(CustomerList& customers)
{
	string name, title;
	Customer cust;
	cout << "Enter customer name: ";
	getline(cin, name);
	cust = customers.getCustomerByName(name);
	OrderList orders;
	orders = cust.getOrders();

	if (customers.SearchCustomerByName(name))
	{
		cout << "Enter the book title to be canceled: ";
		getline(cin, title);
		cust.CancelOrder(title);
		customers.UpdateCustomer(cust);
		cout << "The order is canceled.\n";
	}
	else
	{
		cout << "Customer does not exist.\n" << endl;
	}
}

void PrintOrders(CustomerList& customers)
{
	cout << customers;
}

void CheckoutOrders(CustomerList& customers)
{
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

void UpdateDataFile(CustomerList& customers)
{
	ofstream inFile;
	inFile.open("BookOrders.txt");
	customers.UpdateDataFile(inFile);
	inFile.close();
}
